class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < n ; i++)
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);
        function<int(int)> dfs = [&](int emp){
            int time = 0;
            for(int sub : adj[emp])
                time = max(time , dfs(sub));
            return informTime[emp] + time;
        };
        return dfs(headID);  
    }
};