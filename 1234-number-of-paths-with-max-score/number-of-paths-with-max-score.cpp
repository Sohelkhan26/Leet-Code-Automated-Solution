class Solution {
public:
    int dp[101][101][2] , mod = 1e9 + 7 , n;
    pair<int,int> solve(int x , int y , vector<string>& grid){
        if(x == 0 and y == 0)
            return {0 , 1};
        if(min(x , y) < 0 or x >= n or y >= n or grid[x][y] == 'X')
            return {INT_MIN , 0};
        if(dp[x][y][0] != -1)
            return {dp[x][y][0] , dp[x][y][1]};
        int num = (grid[x][y] == 'S' ? 0 : grid[x][y] - '0');
        long long path = 0;
        auto up = solve(x - 1 , y , grid);
        auto left = solve(x , y - 1 , grid);
        auto upLeft = solve(x - 1 , y - 1 , grid);
        int curr = max(up.first , max(left.first , upLeft.first));
        if(curr == up.first)
            path += up.second;
        if(curr == left.first)
            path += left.second;
        if(curr == upLeft.first)
            path += upLeft.second;
        dp[x][y][0] = curr + num;
        dp[x][y][1] = path % mod;
        return {dp[x][y][0] , dp[x][y][1]};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        memset(dp , -1 , sizeof(dp));
        auto ans = solve(n - 1 , n - 1 , board);
        return (ans.first < 0) ? vector<int> {0 , 0} : vector<int> {ans.first , ans.second};
    }
};