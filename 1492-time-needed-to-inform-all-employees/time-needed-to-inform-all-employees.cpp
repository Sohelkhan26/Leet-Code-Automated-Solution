class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        queue <pair<int,int>> q; // {dist , employee}
        q.push({0 , headID});
        int ans = INT_MIN;
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < n ; i++)
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);
        while(not q.empty()){
            int len = q.size();
            while(len--){
                auto [dist , emp] = q.front(); q.pop();
                ans = max(ans , dist);
                for(int sub : adj[emp]){
                    q.push({dist + informTime[emp] , sub});
                }
            }
        }
        return ans;
    }
};