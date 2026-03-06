class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<pair<int, int>> temp_stack;
        for(int i=0; i<n; i++) {
            int temp = temperatures[i];
            while(temp_stack.empty()==0 && temp>temp_stack.top().first) {
                auto pair = temp_stack.top();
                temp_stack.pop();
                result[pair.second] = i - pair.second;
            }
            temp_stack.push({temp, i});
        }
        return result;
    }
}