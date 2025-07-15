class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int row = classroom.size() , col = classroom[0].size() , litter = 0;
        int sI , sJ , g = 0;
        int dir[5] = {1 , 0 , -1 , 0 , 1};

        auto valid = [&](int i , int j){
            return min(i , j) >= 0 and i < row and j < col;
        };

        map <pair<int,int> , int> group;

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(classroom[i][j] == 'S')
                    sI = i , sJ = j;
                if(classroom[i][j] == 'L'){
                    group[{i , j}] = g++; // give each litter a unique id for masking
                    litter++;
                }
            }
        }
        int all = (1 << litter) - 1;
        bool vis[20][20][1 << 10][51] = {}; 
        vis[sI][sJ][0][energy] = true;
        queue <array<int,5>> q; // {x , y , step , litterMask , energy}
        q.push({sI , sJ , 0 , 0 , energy});
        while(not q.empty()){
            int len = q.size();
            while(len--){
                auto it = q.front(); q.pop();
                int i = it[0] , j = it[1] , step = it[2] , mask = it[3] , en = it[4];
                if(mask == all)
                    return step;
                for(int k = 0 ; k < 4 ; k++){
                    int newI = i + dir[k] , newJ = j + dir[k + 1];
                    if(valid(newI , newJ) and classroom[newI][newJ] != 'X'){
                        int newMask = mask , newEn = en - 1;
                        if(newEn < 0)continue; // must have 1 energy to go to newI , newJ
                        if(classroom[newI][newJ] == 'R')
                            newEn = energy ;
                        if(classroom[newI][newJ] == 'L')
                            newMask |= (1 << group[{newI , newJ}]);
                        if(not vis[newI][newJ][newMask][newEn]){
                            q.push({newI , newJ , step + 1 , newMask , newEn});
                            vis[newI][newJ][newMask][newEn] = true;
                        }
                    }
                }
            }   
        }
        return -1;
    }
};

/*
Very good problem. Never seen anything like this.
After seeing code it may not seem complicated. But it's hard to figure out BFS will bitmasking to track visited state solves the problem.
Main trick to apply BFS is same cells can be visited multiple times.  
*/