class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size() , used = 0 , ans = 0;
        for(int left = 0 , right = 0 ; right < n ; right++){
            while((used & nums[right]) != 0)
                used ^= nums[left++];
            used |= nums[right];
            ans = max(ans , right - left + 1);
        }
        return ans;
    }
};