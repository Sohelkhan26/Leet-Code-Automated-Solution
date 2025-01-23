class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size() , m = isWater[0].size();
        vector<vector<int>> ans(n , vector <int> (m , -1));
        queue <vector<int>> q;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(isWater[i][j])
                    ans[i][j] = 0 , q.push({0 , i , j});
        while(not q.empty()){
            auto it = q.front(); q.pop();
            int height = it[0] , i = it[1] , j = it[2];
            height++;
            for(auto [di , dj] : vector <pair<int,int>> {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}}){
                int newI = i + di , newJ = j + dj;
                if(min(newI , newJ) >= 0 and newI < n and newJ < m and ans[newI][newJ] == -1){
                    ans[newI][newJ] = height;
                    q.push({height , newI , newJ});
                }
            }
        }
        return ans;
    }
};