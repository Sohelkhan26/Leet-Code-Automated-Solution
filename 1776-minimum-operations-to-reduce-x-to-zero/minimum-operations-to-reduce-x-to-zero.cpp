class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size() , ans = n + 1 , window = 0 , total = accumulate(nums.begin() , nums.end() , 0);
        for(int left = 0 , right = 0 ; right < n ; right++){
            window += nums[right];
            while(left <= right and (total - window) < x)
                window -= nums[left++];
            if((total - window) == x)
                ans = min(ans , n - (right - left + 1));
        }
        return ans == n + 1 ? -1 : ans;
    }
};