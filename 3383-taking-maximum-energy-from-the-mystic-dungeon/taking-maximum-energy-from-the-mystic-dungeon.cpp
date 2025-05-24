class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN , n = energy.size();
        vector<int> dp(n , -1);
        function<int(int)> solve = [&](int i){
            if(i >= n)
                return 0;
            if(dp[i] != -1)
                return dp[i];
            int take = energy[i] + solve(i + k);
            return dp[i] = take;
        };
        for(int i = 0 ; i < n ; i++)
            ans = max(ans , solve(i));
        return ans;
    }
};