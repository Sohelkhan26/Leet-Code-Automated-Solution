class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() , ans = 0;
        for(int i = 0 ; i < n ; i++){ 
            for(int j = 0 ; j < m ; j++){ 
                for(int len = 1 ; i + len <= n and j + len <= m ; len++){
                    bool ok = true;
                    for(int k = 0 ; k < len ; k++){
                        if(grid[i][j + k] == 0) // first row
                            ok = false;
                        if(grid[i + len - 1][j + k] == 0) // last row
                            ok = false;
                        if(grid[i + k][j] == 0) // first col
                            ok = false;
                        if(grid[i + k][j + len - 1] == 0) // last col
                            ok = false;
                    }
                    // for(int k = 0 ; k < len ; k++){
                    // }
                    if(ok)
                        ans = max(ans , len * len);
                }
            }
        }
        return ans;
    }
};