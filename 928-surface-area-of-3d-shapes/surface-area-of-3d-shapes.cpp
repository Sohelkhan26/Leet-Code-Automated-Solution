class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0 , n = grid.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j])
                    ans += grid[i][j] * 4 + 2;
                if(i)ans -= min(grid[i][j] , grid[i - 1][j]) * 2;
                if(j)ans -= min(grid[i][j] , grid[i][j - 1]) * 2;
            }
        }
        return ans;
    }
};

/*
Quite hard for a easy problem.
Every cube has 1 * 1 * 1 dimension. So surface of every cube is 1 * 6 = 6. cube has 6 side. Every tower has 4 * v + 2 surface area.
Add every towers surface area to answer and don't forget to subtract common area of two adjacent towers. Common area along x and y axis. Minimum of two adjacent tower side.
*/