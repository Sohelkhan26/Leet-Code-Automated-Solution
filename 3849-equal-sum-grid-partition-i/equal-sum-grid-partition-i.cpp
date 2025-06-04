class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        long long total = 0;
        vector <long long> row(n) , col(m);
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                row[i] += grid[i][j] , col[j] += grid[i][j] , total += grid[i][j];
        for(int i : row)
            cout << i << ' ';
        cout << endl;
        for(int i : col)
            cout << i << ' ';
        for(int i = 0 ; i < n ; i++){
            if(i)
                row[i] += row[i - 1];
            if(row[i] == (total - row[i]))
                return true;
        }
        for(int i = 0 ; i < m ; i++){
            if(i)
                col[i] += col[i - 1];
            if(col[i] == (total - col[i]))
                return true;
        }
        return false;
    }
};