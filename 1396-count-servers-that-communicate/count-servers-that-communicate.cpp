class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0 , n = grid.size() , m = grid[0].size();
        vector <int> rowCount(n) , colCount(m);
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(grid[i][j])
                    rowCount[i]++ , colCount[j]++;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(grid[i][j])
                    ans += (rowCount[i] > 1 or colCount[j] > 1);
        return ans;
    }
};