class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int component = n , m = edges.size();
        sort(edges.begin() , edges.end() , [&](auto &a , auto &b){
            return a[2] < b[2];
        });
        vector<int> parent(n , -1);
        function<int(int)> find = [&](int i){
            if(parent[i] == -1)
                return i;
            return parent[i] = find(parent[i]);
        };
        auto Unite = [&](int a , int b){
            a = find(a) , b = find(b);
            if(a == b)
                return false;
            parent[a] = b;
            return true;
        };
        for(int i = m - 1 ; i >= 0 ; i--){
            component -= (Unite(edges[i][0] , edges[i][1]));
            if(component < k)
                return edges[i][2];
        }
        return 0;
    }
};

/*
minimum time 't' such that even after removing all edges with time <= t there are >= k connected components.
If edges is sorted by time and after removing from the end, at a time, there are < k components then what?
Those last edges form <= k components? Then we found the answer?

*/