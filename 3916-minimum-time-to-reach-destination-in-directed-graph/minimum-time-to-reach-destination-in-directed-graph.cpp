class Solution {
public:
    typedef pair<int,int> p;
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<array<int,3>>> adj(n);
        vector<int> dist(n , INT_MAX);
        dist[0] = 0;
        for(auto &e : edges){
            int u = e[0] , v = e[1] , start = e[2] , end = e[3]; 
            adj[u].push_back({v , start , end}); // if cycle then?
        }
        priority_queue <p , vector<p> , greater<p> > pq;
        pq.push({0 , 0});
        while(not pq.empty()){
            auto [time , curr] = pq.top(); pq.pop();
            if(curr == n - 1)
                return time;
            if(dist[curr] < time)
                continue;
            for(auto it : adj[curr]){
                int nei = it[0] , start = it[1] , end = it[2];
                if(time > end)
                    continue;
                int newTime = max(time + 1 , start + 1);
                if(dist[nei] > newTime)
                    pq.push({newTime , nei}) , dist[nei] = newTime;
            }
        }
        return -1;
    }
};

/*
Given n nodes and edges. edge = [source , destination , start , end]
Edge can be visited if start <= time <= end
Graph could contain cycle???
start , end <= 1e9 , so can't simulate time increasing one by one.
Out of all neighbors, they can be visited by current Time + 1 , or start Time + 1 , extra 1 for traversing the edge . That time must be <= end
To avoid visiting one node multiple times, keep a distance array.
Or keeping parent could work too? Nah, it don't work.
*/