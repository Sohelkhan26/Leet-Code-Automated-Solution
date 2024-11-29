class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue < vector<int> , vector<vector<int>> , greater<vector<int>> > pq;
        pq.push({0 , 0 , 0});
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> dp(n , vector<int> (m , INT_MAX));
        dp[0][0] = 0;
        vector<pair<int,int>> path = {{100,100} , {0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}}; // We stored the direction according to the grid's value. 1 means go right. So we stored [dx , dy] = {0 , 1} which is for right in the first cell. First direction is dummy value doesn't matter.
        while(not pq.empty()){
            auto it = pq.top(); pq.pop();
            int cost = it[0] , x = it[1] , y = it[2];
            if(dp[x][y] > cost)
                continue;
            for(int i = 1 ; i < 5 ; i++){
                auto [dx , dy] = path[i];
                int newX = x + dx , newY = y + dy;
                if(min(newX , newY) >= 0 and newX < n and newY < m){
                    int newCost = cost + (i != grid[x][y]);
                    if(dp[newX][newY] > newCost){
                        dp[newX][newY] = newCost;
                        pq.push({newCost , newX , newY});
                    }
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
/*
আবারো Dijkstra. কোন সেল যেদিকে পয়েন্ট করে আছে সেই সেলে গেলে cost same থাকবে। অন্যথায় cost এক করে বাড়বে। Simple Dijkstra থেকে একটু ভিন্ন। একবার ভিজিট করে মার্ক করে ফেললে হবে না। পরে হয়তোবা একই সেলে কম cost এ পৌছানো যাবে। Cell pointing এর বিষয় টা বেশ মজার। 
Main thing about this problem is we may need to visit one cell multiple times. But don't visit cells unnecessarily. And neighbouring cells that matches the current cell's direction requires no extra cost.
*/