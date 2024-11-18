class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size() , ans = 0;
        auto calcPref = [&](char c) {
            vector<vector<int>> pref(n , vector<int> (m));
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    pref[i][j] = (grid[i][j] == c);
                    pref[i][j] += (i ? pref[i - 1][j] : 0) + (j ? pref[i][j - 1] : 0) - (i and j ? pref[i - 1][j - 1] : 0);
                }
            }
            return pref;
        };
        vector<vector<int>> xCount = calcPref('X');
        vector<vector<int>> yCount = calcPref('Y');
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(xCount[i][j] == yCount[i][j] and xCount[i][j])
                    ans++;
        return ans;
    }
};