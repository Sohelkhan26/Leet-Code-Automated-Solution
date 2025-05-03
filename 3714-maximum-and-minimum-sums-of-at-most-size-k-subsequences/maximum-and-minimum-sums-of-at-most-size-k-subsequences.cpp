class Solution {
public: 
    int minMaxSums(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int n = nums.size() , ans = 0 , mod = 1e9 + 7;
        vector<vector<int>> nCr(nums.size() + 1, vector<int> (k + 1,0));
        nCr[0][0] = 1;
        for (int n = 1; n <= nums.size(); n++) {
            nCr[n][0] = 1;
            for (int r = 1; r <= k; r++) 
                nCr[n][r] = (nCr[n - 1][r - 1] + nCr[n - 1][r]) % mod;
        } 
        for(int i = 0 ; i < n ; i++){
            for(int len = 1 ; len <= k ; len++){
                int N = n - i - 1 , R = len - 1;
                ans = (ans + 1ll * nCr[N][R] * nums[i]) % mod;
                N = i;
                ans = (ans + 1ll * nCr[N][R] * nums[i]) % mod;
            }
        }
        return ans;
    }
};