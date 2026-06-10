class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> track;

        for(int i = 0;i<nums.size();i++){
            if(track.contains(nums[i])){
                return nums[i];
            }
            track[nums[i]]++;
        }
        return -1;
    }
};
