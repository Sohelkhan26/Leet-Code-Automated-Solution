class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue <int> q;
        q.push(start);
        int n = arr.size();
        vector <int> vis(n);
        while(not q.empty()){
            int len = q.size();
            while(len--){
                int i = q.front(); q.pop();
                if(arr[i] == 0)
                    return true;
                int a = i + arr[i] , b = i - arr[i];
                auto valid = [&](int a){
                    return a >= 0 and a < n and not vis[a];
                };
                if(valid(a))q.push(a) , vis[a] = true;
                if(valid(b))q.push(b) , vis[b] = true;
            }
        }
        return false;
    }
};