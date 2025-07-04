class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector <int> inDegree(n) , ans;
        for(auto &e : edges)
            inDegree[e[1]]++;
        for(int i = 0 ; i < n ; i++)
            if(not inDegree[i])
                ans.push_back(i);
        return ans;
    }
};