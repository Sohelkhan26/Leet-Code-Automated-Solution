class Solution {
public:
    vector<vector<int>> grid;
    int dir[5] = {1 , 0 , -1 , 0 , 1} , N;
    int dp[501][501][4];
    int maxArm(int r , int c , int d){
        if(min(r , c) < 0 or r >= N or c >= N or grid[r][c] == 0)
            return 0;
        if(dp[r][c][d] != -1)
            return dp[r][c][d];
        return dp[r][c][d] = 1 + maxArm(r + dir[d] , c + dir[d + 1] , d);
    }
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        memset(dp , -1 , sizeof(dp));
        grid.resize(n , vector <int> (n , 1));
        N = n;
        for(auto &m : mines)
            grid[m[0]][m[1]] = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int arm = 5001;
                for(int k = 0 ; k < 4 ; k++)
                    arm = min(arm , maxArm(i , j , k));
                ans = max(ans , arm);
            }
        }
        return ans;
    }
};

/*
Such an elegant problem. Brute force don't get accepted.
For every 1 as core start expanding 1 to left , right , up and down. Minimum is the arm length of the plus sign. Out of all possibilities return the maximum.
To efficiently calculate the maxium arm length of possible(series of 1 in some direction) we can use DP. dp[r][c][d] denotes maximum arm length in the direction "d" and [r , c] as it's center. The use of "d" as direction is clever. Refer to dir[5] array. Each combination signifies a direction.
*/