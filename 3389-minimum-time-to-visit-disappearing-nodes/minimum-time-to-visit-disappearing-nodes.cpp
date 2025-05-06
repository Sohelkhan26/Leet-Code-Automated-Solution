typedef long long ll;
typedef pair<ll , ll> P;
vector<int> Dijktra(vector<vector<int>> &edges , int source , int n , vector <int> &disappear){
    ll from , distance;
    vector<vector<P>> adj(n);
    vector <int> dist(n , INT_MAX);
    for(auto it : edges){
        int from = it[0] , to = it[1] , weight = it[2];
        adj[from].push_back({weight , to});
        adj[to].push_back({weight , from});
    }
    priority_queue <P , vector <P> , greater<P>> pq;
    dist[source] = 0;
    pq.push({0 , source});
    while(not pq.empty()){
        from = pq.top().second , distance = pq.top().first;
        pq.pop();
        if(distance > dist[from])continue;
        for(auto it : adj[from]){
            ll to = it.second , distance = it.first;
            distance += dist[from];
            if(distance >= dist[to] or distance >= disappear[to])
                continue;
            dist[to] = distance;
            pq.push({distance , to});
        }
    }
    return dist;
}


class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector <int> ans = Dijktra(edges , 0 , n , disappear);
        for(int &i : ans)
            if(i == INT_MAX)
                i = -1;
        return ans;
    }
};

/*
undirected edge, i'th node disappears at disappear[i], graph could be diconnected and have multiple edge. Edge all positive. Dijkstra? Simple dijkstra if distance < disappear[i] assign -1?
*/