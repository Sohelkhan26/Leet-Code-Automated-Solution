class Solution {
public:
    vector <long long> dp;
    int n;
    long long solve(int i , vector<int> &power){
        if(i == n)
            return 0ll;
        if(dp[i] != -1)
            return dp[i];
        long long take = 0;
        int j = i;
        while(j < n and power[i] == power[j])
            take += power[j++];
        long long dont = solve(j , power);
        while(j < n and (power[j] == power[i] + 1 or power[j] == power[i] + 2))
            j++;
        take += solve(j , power);
        return dp[i] = max(take , dont);
    }
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin() , power.end());
        n = power.size();
        dp.resize(n , -1);
        return solve(0 , power);
    }
};