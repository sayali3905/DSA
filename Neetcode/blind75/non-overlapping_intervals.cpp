class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int removal=0;
        sort(intervals.begin(), intervals.end());
        vector<int> last = intervals[0];
        for(int i=1; i<n; i++) {
            if(last[1]>intervals[i][0]) {
                last[1] = min(intervals[i][1], last[1]);
                removal++;
            }
            else {
                last = intervals[i];
            }
        }
        return removal;
    }
};