class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0 , n = nums.size() , window = 1;
        for(int left = 0 , right = 0 ; right < n ; right++){
            window *= nums[right];
            while(left <= right and window >= k)
                window /= nums[left++];
            ans += right - left + 1;
        }
        return ans;
    }
};