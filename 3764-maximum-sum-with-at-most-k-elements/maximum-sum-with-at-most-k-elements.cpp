class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        vector <pair<int,int>> v;
        long long ans = 0 , n = grid.size() , m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++)
                v.push_back({grid[i][j] , i});
        }
        sort(v.rbegin() , v.rend());
        for(int i = 0 ; i < v.size() ; i++){
            int idx = v[i].second , val = v[i].first;
            if(limits[idx] and k)
                ans += val , limits[idx]-- , k--;
        }
        return ans;
    }
};