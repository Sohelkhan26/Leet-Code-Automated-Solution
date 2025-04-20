class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size() , m = grid[0].size();
        auto valid = [&](int i , int j){
            return min(i , j) >= 0 and i < n and j < m;
        };
        set <pair<int,int>> vis;
        int dir[] = {1 , 0 , -1 , 0 , 1};
        function<void(int,int,int)> dfs = [&](int i , int j , int origin){
            vis.insert({i , j});
            bool isBorder = false;
            for(int k = 0 ; k < 4 ; k++){
                int newI = i + dir[k] , newJ = j + dir[k + 1];
                if(vis.contains({newI , newJ}))
                    continue;
                if(not valid(newI , newJ))
                    isBorder = true;
                else if(grid[newI][newJ] != origin)
                    isBorder = true;
                else dfs(newI , newJ , origin);
            }
            if(isBorder)
                grid[i][j] = color;
        };
        dfs(row , col , grid[row][col]);
        return grid;
    }
};