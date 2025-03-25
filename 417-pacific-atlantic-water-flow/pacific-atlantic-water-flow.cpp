class Solution {
public:
    int n , m;
    void dfs(int i , int j , vector<vector<int>> &h , set <pair<int,int>> &visit , int prevH){
        if(min(i , j) < 0 or i == n or j == m or visit.contains({i , j}) or h[i][j] < prevH)
            return;
        visit.insert({i , j});
        int dir[] = {1 , 0 , -1 , 0 , 1};
        for(int k = 0 ; k < 4 ; k++){
            int newI = i + dir[k] , newJ = j + dir[k + 1];
            dfs(newI , newJ , h , visit , h[i][j]);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set <pair<int,int>> atlantic , pacific;
        n = heights.size() , m = heights[0].size();

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++){
                if(i == 0 or j == 0)
                    dfs(i , j , heights , pacific , heights[i][j]);
                if(i == n - 1 or j == m - 1)
                    dfs(i , j , heights , atlantic , heights[i][j]);
                }

        vector<vector<int>> ans;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(atlantic.contains({i , j}) and pacific.contains({i , j}))
                    ans.push_back({i , j});
        return ans;
    }
};