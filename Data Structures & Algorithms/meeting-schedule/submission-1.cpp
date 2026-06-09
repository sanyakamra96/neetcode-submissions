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
        sort(intervals.begin(),intervals.end(),[](Interval& a,Interval&b){
            return a.start<b.start;
        });
        int n = intervals.size();
        int check=0;
        for(int i=0; i<n;i++){
            if(check>intervals[i].start){
                return false;
            }
                check = intervals[i].end;
        }
        return true;
    }
};
