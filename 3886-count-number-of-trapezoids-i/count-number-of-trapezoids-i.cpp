class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map <int,set <int>> freq;
        for(auto &p : points)
            freq[p[1]].insert(p[0]);
        int ans = 0 , mod = 1e9 + 7 , pref = 0;
        for(auto &[y , st] : freq){
            int n = st.size();
            int curr = (1LL * n * (n - 1) / 2) % mod;
            ans = (0LL + ans + 1LL * pref * curr) % mod;
            pref += curr;
        }
        return ans;
    }
};