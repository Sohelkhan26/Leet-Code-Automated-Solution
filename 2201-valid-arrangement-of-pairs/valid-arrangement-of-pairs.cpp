class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map <int , deque <int>> adj;
        unordered_map <int,int> inDegree , outDegree; // 1 <= pairs[i] <= 1e9
        for(auto &pair : pairs){
            int start = pair[0] , end = pair[1];
            adj[start].push_back(end);
            outDegree[start]++ , inDegree[end]++;
        }
        int dfsBegin = -1;
        for(auto it : outDegree){
            if(it.second == inDegree[it.first] + 1){
                dfsBegin = it.first;
                break;
            }
        }
        dfsBegin = dfsBegin == -1 ? pairs[0][0] : dfsBegin;
        vector<int> res;
        function < void(int) > dfs = [&](int i) -> void{
            while(not adj[i].empty()){
                int neighbour = adj[i].back();
                adj[i].pop_back();
                dfs(neighbour);
            }
            res.push_back(i);
        };
        dfs(dfsBegin);
        reverse(res.begin() , res.end());
        vector<vector<int>> ans;
        for(int i = 1 ; i < res.size() ; i++)
            ans.push_back({res[i - 1] , res[i]});
        return ans;
    }
};