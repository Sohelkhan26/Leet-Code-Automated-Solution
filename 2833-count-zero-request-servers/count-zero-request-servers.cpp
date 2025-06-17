class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int,int>> q;
        int l = logs.size() , m = queries.size();
        for(int i = 0 ; i < m ; i++)
            q.push_back({queries[i] , i});
        sort(q.begin() , q.end()); 
        sort(logs.begin() , logs.end() , [&](auto &a , auto &b){
            return a[1] < b[1]; // sort by time in logs = {id , time}
        });
        int left = 0 , right = 0;
        unordered_map <int,int> window;
        vector <int> ans(m);
        for(int i = 0 ; i < m ; i++){
            int ind = q[i].second , end = q[i].first , start = end - x;
            while(right < l and logs[right][1] <= end) // logs = {id , time} , we have to find window with [s , e] which is inside [start , end]
                window[logs[right++][0]]++;
            while(left < l and logs[left][1] < start){
                if(--window[logs[left][0]] == 0) 
                    window.erase(logs[left][0]);
                left++;
            }
            ans[ind] = n - window.size();
        }
        return ans;
    }
};