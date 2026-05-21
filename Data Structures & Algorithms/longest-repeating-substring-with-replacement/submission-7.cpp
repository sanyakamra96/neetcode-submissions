class Solution {
public:
    int characterReplacement(string s, int k) {
        int window = 0;
        int left = 0;
        int right = 0;
        int most = 0;
        int best = 0;
        int check = 0;
        unordered_map<char,int> track;

        while(right < s.size()){
            track[s[right]]++;
            window = right - left + 1;

            most = max(track[s[right]],most);

            check = window - most;
            while(check > k){
                track[s[left]]--;
                left++;
                window = right - left + 1;
                check = window - most;
            }
            right++;
            best = max(best,window);
        }
        return best;
    }
};