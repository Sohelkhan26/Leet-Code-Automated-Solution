class Solution {
public:
    int n , totalCost = 0;
    vector<vector<int>> adj;
    vector<int> contrib;

    int dp[51][51][2];

    bool dfs(int curr , int par , int dest , vector<int> &price){ // DFS will return true along a path
        if(curr == dest)
            return true;
            
        for(int nei : adj[curr])
            if(nei != par and dfs(nei , curr , dest , price)){
                totalCost += price[nei];
                contrib[nei]++;
                return true;
            }
        return false;
    }

    int solve(int curr , int par , bool canHalve , vector<int> &price){
        if(dp[curr][par][canHalve] != -1)
            return dp[curr][par][canHalve];

        int ans = 0;
        if(canHalve) // since calculating only discount
            ans += (price[curr] / 2) * contrib[curr];
        for(int nei : adj[curr]){
            if(nei != par){
                int a = 0 , b = 0 , c = 0;
                if(canHalve) // if we half this node, can't halve children
                    a = solve(nei , curr , false , price);
                else // if we don't half this node, we can half/skip childrens
                    b = solve(nei , curr , false , price) , c = solve(nei , curr , true , price);
                ans += max(a , max(b , c)); // take the maximum path
            }
        }
        return dp[curr][par][canHalve] = ans;
    }
    int minimumTotalPrice(int N, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        n = N;

        adj = vector<vector<int>> (n);
        contrib = vector<int> (n);
        memset(dp , -1 , sizeof(dp));

        for(auto &e : edges)
            adj[e[0]].push_back(e[1]),
            adj[e[1]].push_back(e[0]); 

        for(auto &t : trips){
            int start = t[0] , end = t[1]; 
            totalCost += price[start]; // structure of DFS excludes the starting node
            contrib[start]++; // so calculate it seperately
            dfs(start , start , end , price);
        }

        int ans = totalCost;

        for(int i = 0 ; i < n ; i++){
            ans = min(ans , totalCost - solve(i , i , true , price));
            ans = min(ans , totalCost - solve(i , i , true , price));
        }
        return ans;
    }
};

/*
Given a unrooted tree with n nodes. and n - 1 edges
each node has an price. You can choose some non adjacent nodes and halve the price. Better to choose all non-adjacent nodes and halve? Greedy don't work. Have to apply Dp.
for each trip[i] = {start , end} find minimal path 
and return sum of all trips

For a tree there is an unique path between any two nodes.
So, we can't minimize cost by choosing some other nodes. Have to reduce cost
choosing to halve a node or not.

All trips can be merged and each nodes contribution in the path of each trips can be calculated.
Since it's a unrooted tree, we can choose any node as root and apply DP. To use same memoization table, we need 2D DP, otherwise reset 1D Dp for each solve function call?

Dp will calculate maximum discount achievable for all nodes present in any trip.
*/