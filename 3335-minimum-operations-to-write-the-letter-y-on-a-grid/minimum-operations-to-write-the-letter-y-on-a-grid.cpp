class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        auto partOfY = [&](int i , int j){
            if(i <= n / 2)
                return i == j or i + j == n - 1;
            return j == n / 2;
        };
        auto count = [&](int y , int notY){
            int change = 0;
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(partOfY(i , j)) // we intend to fill "Y" part with y values
                        change += (grid[i][j] != y);
                    else // and non-Y parth with notY values.
                        change += (grid[i][j] != notY);
                }
            }
            return change;
        };
        int ans = INT_MAX;
        for(int y = 0 ; y < 3 ; y++)
            for(int notY = 0 ; notY < 3 ; notY++){
                if(y == notY)continue;
                ans = min(ans , count(y , notY));
            }
        return ans;
    }
};

/*
Seemed like DP at first. 
Requirement is y-cell-values can't be equal to non-y-cell-values and their own values should be same too. There are only 6 combination, for the 3 values. 3P2.
Write a function that will determine operation count based on those combination.Take the min.
*/