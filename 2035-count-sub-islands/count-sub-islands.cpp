// class Solution {
// public:
//     int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
//         int n = grid1.size() , m = grid[0].size() , ans = 0;
//         function<bool(int,int)> dfs = [&](int i , int j) -> bool{

//         };
//     }
// };

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size() , m = grid1[0].size();
        vector<vector<bool>> vis(n , vector<bool> (m , false));
        function <bool(int,int)> dfs = [&](int i , int j) -> bool{
            bool ans = true;
            if(grid1[i][j] != grid2[i][j])
                ans = false;
            for(auto [di , dj] : vector<pair<int,int>> {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}}){
                int newi = i + di , newj = j + dj;
                if(min(newi , newj) >= 0 and newi < n and newj < m and vis[newi][newj] == false and grid2[newi][newj]){
                    vis[newi][newj] = true;
                    ans &= dfs(newi , newj);
                }
            }
            return ans;
        };
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid2[i][j] and vis[i][j] == false){
                    vis[i][j] = true;
                    ans += dfs(i , j);
                }
            }
        }
        return ans;
    }
};