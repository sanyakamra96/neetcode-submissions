class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1);

        int start = 0;
        int best = 0;

        for (int end = 0; end < s.size(); end++) {
            char c = s[end];

            if (lastSeen[c] >= start) {
                start = lastSeen[c] + 1;
            }

            lastSeen[c] = end;
            best = max(best, end - start + 1);
        }

        return best;
    }
};