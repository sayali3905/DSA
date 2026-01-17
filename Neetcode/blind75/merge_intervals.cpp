class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.empty()) {
            return result;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> last;
        last = intervals[0];
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0]<=last[1]) {
                last[1] = max(last[1], intervals[i][1]);
            }
            else {
                result.push_back(last);
                last = intervals[i];
            }
        }
        result.push_back(last);
        return result;
    }
};