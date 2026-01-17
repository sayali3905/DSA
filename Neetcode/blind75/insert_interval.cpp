class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i=0;
        for(; i<intervals.size() && newInterval[0]>intervals[i][1]; i++) {
            result.push_back(intervals[i]);
        }
        for(; i<intervals.size() && newInterval[1]>=intervals[i][0]; i++) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }   
        result.push_back(newInterval);
        for(; i<intervals.size(); i++) {
            result.push_back(intervals[i]);
        }
        return result;
    }
};