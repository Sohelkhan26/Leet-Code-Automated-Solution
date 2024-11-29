class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() , mod = 1e9 + 7;
        vector<vector<int>> dp(n , vector<int> (m , -1));
        function<int(int , int)> solve = [&](int i , int j) -> int{
            if(dp[i][j] != -1)
                return dp[i][j];
            dp[i][j] = 1;
            for(auto &[di , dj] : vector<pair<int,int>> {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}}){
                int newi = i + di , newj = j + dj;
                if(min(newi , newj) >= 0 and newi < n and newj < m){
                    if(grid[newi][newj] > grid[i][j])
                        dp[i][j] += solve(newi , newj) % mod;
                }
            }
            return dp[i][j] % mod;
        };
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans = (ans + solve(i , j) % mod) % mod;
            }
        }
        return ans;
    }
};

/*
একটা হিন্ট দেখার পর পারছি। প্রতিটা সেল এ দেখতে হবে এই সেল থেকে শুরু করলে কয়টা Increasing path পাবো। Memoise করার ক্ষেত্রে একটা জিনিস মাথায় রাখতে হবে, কোন সেলের [i , j] জন্য একটা Increasing path আগে পাওয়া গেছিলো সেই কারনে সেটা DP তে স্টোর করা আছে। কিন্তু বর্তমান সেলের [r , c] জন্য সেটা ভ্যালিড হবে যদি grid[i][j] > grid[r][c] হয়। প্রতিটা সেলের জন্য solve function call করতে হবে। 
*/