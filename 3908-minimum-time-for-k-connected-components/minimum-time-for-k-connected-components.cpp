class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int m = edges.size();
        if(m == 0)
            return 0;
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
        int low = 0 , high = edges[m - 1][2] , mid , ans = 0;
        while(low <= high){
            mid = low + (high - low) / 2;
            int component = n;
            parent.assign(n , -1);
            for(int i = m - 1 ; i >= 0 ; i--){
                if(edges[i][2] <= mid)
                    break;
                component -= (Unite(edges[i][0] , edges[i][1]));
            }
            if(component >= k)
                ans = mid , high = mid - 1;
            else low = mid + 1;
        }
        return ans;
    }
};

/*
minimum time 't' such that even after removing all edges with time <= t there are >= k connected components.
If edges is sorted by time and after removing from the end, at a time, there are < k components then what?
Those last edges form <= k components? Then we found the answer?

*/