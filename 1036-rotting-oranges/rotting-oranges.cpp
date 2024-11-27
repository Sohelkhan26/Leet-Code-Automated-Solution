class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        auto check = [&]() -> bool{
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < m ; j++)
                    if(grid[i][j] == 1)
                        return false;
            return true;
        };
        auto BFS = [&]() -> int{
            int level = 0;
            queue <pair<int,int>> q;
            for(int i = 0 ; i < n ; i++)   
                for(int j = 0 ; j < m ; j++)
                    if(grid[i][j] == 2)
                        q.push({i , j});
            while(not q.empty()){
                int len = q.size();
                while(len--){
                    auto [i , j] = q.front(); q.pop();
                    grid[i][j] = 2;
                    for(auto [di , dj] : vector<pair<int,int>> {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}}){
                        int newi = i + di , newj = j + dj;
                        if(min(newi , newj) >= 0 and  newi < n and newj < m and grid[newi][newj] == 1)
                            q.push({newi , newj});
                    }
                }
                level++;
                if(check()) 
                    break;
            }
            if(check())
                return level ? level - 1 : 0;
            return -1;
        };
        return BFS();
    }
};