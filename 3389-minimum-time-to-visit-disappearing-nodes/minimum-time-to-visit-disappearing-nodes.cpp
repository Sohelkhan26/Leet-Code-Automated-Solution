class Solution {
public:
    typedef pair<int,int> p;
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<p>> adj(n);
        vector <int> dist(n , INT_MAX);
        for(auto e : edges)
            adj[e[0]].push_back({e[2] , e[1]}),
            adj[e[1]].push_back({e[2] , e[0]});
        auto dijkstra = [&](int source){
            dist[source] = 0;
            priority_queue <p , vector<p> , greater<p>> pq;
            pq.push({0 , source});
            while(not pq.empty()){
                auto [distance , curr] = pq.top(); pq.pop();
                if(distance > dist[curr])
                    continue;
                for(auto &[t , next] : adj[curr]){
                    int time = t + dist[curr];
                    if(time >= dist[next] or time >= disappear[next])
                        continue;
                    dist[next] = time;
                    pq.push({time , next});
                }
            }
        };
        dijkstra(0);
        for(int &i : dist)
            if(i == INT_MAX)
                i = -1;
        return dist;
    }
};

/*
undirected edge, i'th node disappears at disappear[i], graph could be diconnected and have multiple edge.
Edge all positive. Dijkstra? Simple dijkstra if distance < disappear[i] assign -1?
What if multiple edges have same time? There is a time limit to each node. After that it can't be reached.
Dijkstra with slight modification. If there are enough multiple edge it can cause TLE.
So add : if(distance > dist[curr])
                    continue; // Although it is a standard practice in all dijstra related problem but they might get accepted,
                    // but this one won't.
To handle time limit don't go to a node if it has already disappeared.
how to Determine? If time taken to reach a node is >= disappear[node] then don't visit or rather can't visit.
*/