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
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end(),[](Interval& a, Interval& b){
            return a.start<b.start;
        });
       priority_queue<int,vector<int>,greater<int>> min_pq;
        int n = intervals.size();
        int conflict=1;
       for(int i = 0;i<n;i++){
        if(!min_pq.empty() and intervals[i].start<min_pq.top()){
            conflict++;
        }
        else{
            if(!min_pq.empty()){
            min_pq.pop();
            }

        }
        min_pq.push(intervals[i].end);
       }
       return conflict;
    }
};
