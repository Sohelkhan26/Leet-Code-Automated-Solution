class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size() , half = n / 2 , ans = 0;
        unordered_map <int,int> mp;
        for(int i : arr)mp[i]++;
        priority_queue <int> pq;
        for(auto &[_ , cnt] : mp)
            pq.push(cnt);
        while(not pq.empty()){
            int remove = pq.top(); pq.pop();
            n -= remove;
            ans++;
            if(n <= half)
                return ans;
        }
        return ans;
    }
};