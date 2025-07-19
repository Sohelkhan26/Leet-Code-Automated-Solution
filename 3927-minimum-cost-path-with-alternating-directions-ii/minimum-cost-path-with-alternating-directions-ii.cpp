class Solution {
public:
    long long minCost(int row , int col, vector<vector<int>>& waitCost) {
        vector<vector<long long>> dist(row , vector<long long> (col , LLONG_MAX));
        dist[0][0] = 1;
        priority_queue <tuple <long long,int,int> , vector<tuple<long long , int , int>> , greater<> > pq;
        pq.push({1 , 0 , 0});

        auto valid = [&](int x , int y){
            return x < row and y < col;
        };

        while(not pq.empty()){
            auto [cost , x , y] = pq.top(); pq.pop();
            if(x == row - 1 and y == col - 1)
                return cost - waitCost[row - 1][col - 1];
            if(dist[x][y] < cost)continue;
            for(auto &[dx , dy] : vector<pair<int,int>> {{1 , 0} , {0 , 1}}){
                int newX = x + dx , newY = y + dy;
                if(valid(newX , newY)){
                    long long newCost = cost + 1ll * (newX + 1) * (newY + 1) + waitCost[newX][newY];
                    if(dist[newX][newY] > newCost)
                        pq.push({newCost , newX , newY}) , dist[newX][newY] = newCost;
                }
            }
        }
        
        return -1;
    }
};