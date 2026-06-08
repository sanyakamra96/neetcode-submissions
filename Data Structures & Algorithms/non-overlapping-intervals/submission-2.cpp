class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int end = -50000;
        int k = 0;
        for(int i = 0; i <intervals.size();i++){
            if(end <= intervals[i][0]){
                end = intervals[i][1];
            }
            else{
                k++;
            }
        }
        return k ;

    }
};
