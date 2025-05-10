class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int firstPerson) {
        vector<pair<int, int>> adj[n];
        meet.push_back({0 , firstPerson , 0}); // subtle but huge
        for(auto it : meet)
            adj[it[0]].push_back({it[1] , it[2]}),
            adj[it[1]].push_back({it[0] , it[2]});
        vector <int> minTime(n , INT_MAX);
        minTime[0] = 0;
        function<void(int , int)> canPass = [&](int curr , int currTime){
            for(auto &[nei , neiTime] : adj[curr]){ // curr node can pass secret to next node if condition is met
                if(neiTime >= currTime and minTime[nei] > neiTime){ // curr node has meeting with "nei" at time = "neiTime", if it is held at a later time than currTime(time when curr node received secret) then curr node can pass secret to neighbor node. "minTime[nei] > neiTime" If neighbour node received secret at a earlier time than currNode then no need to pass it twice. So only DFS call when neighbour time is still greater.
                    minTime[nei] = neiTime;
                    canPass(nei , neiTime);
                }
            }
        };
        canPass(0 , 0);
        vector <int> ans;
        for(int i = 0 ; i < n ; i++)
            if(minTime[i] != INT_MAX)
                ans.push_back(i);
        return ans;
    }
};