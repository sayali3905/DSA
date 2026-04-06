class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> key_map;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        key_map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string result = "";
        auto& values = key_map[key];
        int left = 0;
        int right = values.size()-1;
        while(left<=right) {
            int mid = left + (right-left)/2;
            if(values[mid].first<=timestamp) {
                result = values[mid].second;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            } 
        }
        return result;
    }
};