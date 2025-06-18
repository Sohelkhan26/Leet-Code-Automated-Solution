class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        long long ans = 0 , sum = 0;
        unordered_map <int,int> window;
        for(int left = 0 , right = 0 ; right < n ; right++){
            window[nums[right]]++;
            sum += nums[right];
            if(right - left + 1 > k){
                sum -= nums[left];
                if(--window[nums[left]] == 0)
                    window.erase(nums[left]);
                left++;
            }
            if(right - left + 1 == k and window.size() >= m)
                ans = max(ans , sum);
        }
        return ans;
    }
};