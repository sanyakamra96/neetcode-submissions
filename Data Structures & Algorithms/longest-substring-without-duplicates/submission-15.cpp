class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastseen(256,-1);
        int best = 0;
        int start = 0;
        

        for(int end = 0;end<s.size();end++){

            if(lastseen[s[end]] >=start){
                start = lastseen[s[end]]+1;

            }
            lastseen[s[end]]= end;
            best = max(best,end-start+1);


        }
        return best;
    }
};
