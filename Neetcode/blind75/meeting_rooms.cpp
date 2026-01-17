/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n==0) {
            return true;
        }
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start<b.start;
        });
        Interval last = intervals[0];
        for(int i=1; i<n; i++) {
            if(last.end>intervals[i].start) {
                return false;
            }
            else {
                last = intervals[i];
            }
        }
        return true;
    }
};
