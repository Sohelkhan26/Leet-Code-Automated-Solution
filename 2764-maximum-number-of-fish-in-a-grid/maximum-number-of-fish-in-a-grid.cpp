class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        function<int(int,int)> dfs = [&](int i , int j) -> int{
            int fish = grid[i][j];
            grid[i][j] = 0;
            for(auto [di , dj] : vector<pair<int,int>> {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}}){
                int newI = i + di , newJ = j + dj;
                if(min(newI , newJ) >= 0 and newI < n and newJ < m and grid[newI][newJ] > 0)
                    fish += dfs(newI , newJ);
            }
            return fish;
        };  
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(grid[i][j])
                    ans = max(ans , dfs(i , j));
        return ans;
    }
};