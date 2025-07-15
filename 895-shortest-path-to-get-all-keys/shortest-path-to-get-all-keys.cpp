class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int row = grid.size() , col = grid[0].size();
        int sI , sJ , key = 0;
        int dir[5] = {1 , 0 , -1 , 0 , 1};
        auto valid = [&](int x , int y){
            return min(x , y) >= 0 and x < row and y < col;
        };
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                key += ('a' <= grid[i][j] and grid[i][j] <= 'z');
                if(grid[i][j] == '@')
                    sI = i , sJ = j;
            }
        }
        queue <array<int,4>> q; // {x , y , step , mask}
        int all = (1 << key) - 1;
        bool vis[31][31][1 << 6] = {};
        q.push({sI , sJ , 0 , 0});
        vis[sI][sJ][0] = true;
        while(not q.empty()){
            int len = q.size();
            while(len--){
                auto it = q.front(); q.pop();
                int x = it[0] , y = it[1] , step = it[2] , mask = it[3];
                if(mask == all)
                    return step;
                for(int k = 0 ; k < 4 ; k++){
                    int newX = x + dir[k] , newY = y + dir[k + 1];
                    if(valid(newX , newY) and grid[newX][newY] != '#'){
                        char c = grid[newX][newY];
                        int newMask = mask;
                        if(isupper(c)){
                            bool haveKey = (mask & (1 << (c - 'A')));
                            if(not haveKey) 
                                continue;
                        }else if(islower(c)){
                            newMask |= (1 << (c - 'a'));
                        }
                        if(not vis[newX][newY][newMask]){
                            q.push({newX , newY , step + 1 , newMask});
                            vis[newX][newY][newMask] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};