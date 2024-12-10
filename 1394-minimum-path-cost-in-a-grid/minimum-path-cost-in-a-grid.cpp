class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int row = grid.size() , col = grid[0].size();
        vector<vector<int>> dist(row , vector<int> (col , INT_MAX));
        priority_queue < vector<int> , vector<vector<int>> , greater<> > pq;
        for(int i = 0 ; i < col ; i++)
            pq.push({grid[0][i] , 0 , i}); // cost , row , col
        while(not pq.empty()){
            auto it = pq.top(); pq.pop();
            int cost = it[0] , i = it[1] , j = it[2];
            if(i == row - 1)
                return cost;
            for(int dj = 0 ; dj < col ; dj++){
                int node = grid[i][j] , newCost = cost + moveCost[node][dj] + grid[i + 1][dj];
                if(dist[i + 1][dj] > newCost)
                    pq.push({newCost , i + 1 , dj}) , dist[i + 1][dj] = newCost;
            }
        }
        return -1;
    }
};

/*
This problem was so simple. But I wasted so much time on it. Simpel Dijkstra or DP will solve it.

*/