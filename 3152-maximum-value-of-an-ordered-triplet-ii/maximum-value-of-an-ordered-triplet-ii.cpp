class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0 , n = nums.size();
        vector <int> pref(n) , suff(n);
        pref[0] = nums[0] , suff[n - 1] = nums[n - 1];
        for(int i = 1 ; i < n ; i++)
            pref[i] = max(pref[i - 1] , nums[i]);
        for(int i = n - 2 ; i >= 0 ; i--)
            suff[i] = max(suff[i + 1] , nums[i]);
        for(int i = 1 ; i < n - 1 ; i++)
            ans = max(ans , (pref[i - 1] - nums[i] * 1ll) * suff[i + 1] * 1ll);
        return ans;
    }
};