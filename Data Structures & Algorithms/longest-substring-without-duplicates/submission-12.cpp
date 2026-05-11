class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int end = 0;
        string sub = "";
        int best = 0;
        int start = 0;
        set<char>seen;
        while(end<s.size()){
            if(seen.contains(s[end])){
                seen.erase(s[start]);
                sub.erase(sub.begin());
                start++;
                continue;
            }
            else{
                seen.insert(s[end]);
                sub+=s[end];
                best = max(best,(int)sub.size());
                end++;
            }

        }
        return best;
    }
};
