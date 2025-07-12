class Solution {
public: 
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size() , time = 0;
        queue <array<int,3>> q;
        int dir[5] = {1 , 0 , -1 , 0 , 1};
        auto valid = [&](int x , int y){
            return min(x , y) >= 0 and x < n and y < m;
        };
        q.push({0 , 0 , k});
        vector<vector<vector<bool>>> vis(n , vector<vector<bool>> (m , vector<bool> (k + 1)));
        vis[0][0][k] = true;

        while(not q.empty()){
            int len = q.size();
            while(len--){
                auto it = q.front(); q.pop();
                int x = it[0] , y = it[1] , K = it[2];

                if(x == n - 1 and y == m - 1)
                    return time;

                for(int k = 0 ; k < 4 ; k++){
                    int newX = x + dir[k] , newY = y + dir[k + 1];
                    if(valid(newX , newY)){
                        int newK = K - (grid[newX][newY] == 1);
                        if(newK < 0 or vis[newX][newY][newK])
                            continue;
                        q.push({newX , newY , newK});
                        vis[newX][newY][newK] = true;
                    }
                }
            }
            time++;
        }
        return -1;
    }
};