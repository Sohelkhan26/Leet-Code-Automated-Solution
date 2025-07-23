class Solution {
public:
    int dir[5] = {1 , 0 , -1 , 0 , 1};
    long long dfs(int i , int j , vector<vector<int>> &grid){
        int n = grid.size() , m = grid[0].size();
        if(min(i , j) < 0 or i >= n or j >= m or grid[i][j] == 0)
            return 0;
        long long count = grid[i][j];
        grid[i][j] = 0;
        for(int k = 0 ; k < 4 ; k++)
            count += dfs(i + dir[k] , j + dir[k + 1] , grid);
        return count;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size() , ans = 0;
        unordered_map <long long,int> freq;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] != 0)
                    freq[dfs(i , j , grid)]++;
            }
        }
        for(auto &[sum , cnt] : freq)
            if(sum % k == 0)
                ans += cnt;
        return ans;
    }
};