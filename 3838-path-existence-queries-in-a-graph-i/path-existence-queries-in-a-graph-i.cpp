class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> DSU(n , -1);
        int group = 0;
        DSU[0] = group;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] - nums[i - 1] > maxDiff)
                group++;
            DSU[i] = group;
        }
        vector<bool> ans;
        for(auto &q : queries)
            ans.push_back(DSU[q[0]] == DSU[q[1]]);
        return ans;
    }
};

/*
nums[i] is not the label of the node, but their values. values of all the nodes are given in nums, no node excluded.
If two nodes in the query is in the same component, return true.
How to construct component? DFS? 
If distance between two nodes i , j abs(nums[j] - nums[i]) <= maxDiff they are connected. Since nums is sorted in ascending order, if adjacent two nodes are not connected, nodes further away is gauranteed not to be connected as their difference is greater.
*/