class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue <vector<int> , vector<vector<int>> , greater<> > pq;
        pq.push({grid[0][0] , 0 , 0});
        grid[0][0] = 0;
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> dp(n , vector<int> (m , INT_MAX));
        while(not pq.empty()){
            auto it = pq.top(); pq.pop();
            int obs = it[0] , i = it[1] , j = it[2];
            if(i == n - 1 and j == m - 1)
                return obs;
            for(auto [di , dj] : vector<pair<int,int>> {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}}){
                int newi = i + di , newj = j + dj;
                if(min(newi , newj) >= 0 and newi < n and newj < m and grid[newi][newj] != -1){
                    pq.push({obs + grid[newi][newj] , newi , newj});
                    grid[newi][newj] = -1;
                }
            }
        }
        return 0;
    }
};