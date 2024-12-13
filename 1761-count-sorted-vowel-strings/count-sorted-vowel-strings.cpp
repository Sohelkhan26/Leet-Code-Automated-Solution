class Solution {
public:
    int ans = 0 , N;
    int dp[51][200];
    int solve(int i , char prev){
        if(i == N)
            return 1;
        if(dp[i][(int)prev] != -1)
            return dp[i][(int)prev];
        int ans = 0;
        for(char c : vector<char> {'a' , 'e' , 'i' , 'o' , 'u'}){
            if(c >= prev)   
                ans += solve(i + 1 , c);
        }
        return dp[i][(int)prev] = ans;
    }
    int countVowelStrings(int n) {
        N = n;
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 'a');
    }
};