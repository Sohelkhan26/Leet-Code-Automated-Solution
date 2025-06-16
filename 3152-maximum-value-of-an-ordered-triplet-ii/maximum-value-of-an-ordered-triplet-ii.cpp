class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int left = nums[0] , n = nums.size();
        long long ans = -1;
        vector <int> right(n);
        right[n - 1] = nums[n - 1];

        for(int i = n - 2 ; i >= 0 ; i--)
            right[i] = max(right[i + 1] , nums[i]);

        for(int j = 1 ; j < n - 1 ; j++){
            ans = max(ans , 1ll * (left - nums[j]) * right[j + 1]);
            left = max(left , nums[j]);
        }
        return max(ans , 0ll);
    }
};