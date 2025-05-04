class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector <int> color(n);
        vector<vector<int>> adj(n);
        for(auto &p : paths)
            adj[p[0] - 1].push_back(p[1] - 1),
            adj[p[1] - 1].push_back(p[0] - 1);
        for(int curr = 0 ; curr < n ; curr++){
            vector <bool> usedColor(5);
            for(int nei : adj[curr])
                usedColor[color[nei]] = true; // neighbours color was marked as occupied
            for(int c = 1 ; c <= 4 ; c++)
                if(not usedColor[c]){
                    color[curr] = c;
                    break;
                }
        }
        return color;
    }
};
/*
One garden connected to at most 3 other gardens.
Answer guaranteed.
Do we need backtracking? Or just assign color and simple DFS? If so will there be any conflict?
As the answer is guaranteed, we need not worry about wrong color choice. One solution will always exist.
Based on the initial color on the first garden, the answer may vary but, there is a solution.
So, greedy approach is fine. 
For every node find out neighbour's color and assign the node other then those color. Simple as that.
*/