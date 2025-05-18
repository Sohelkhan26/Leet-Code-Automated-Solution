class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9 + 7 , m = queries.size();
        vector <int> nums , ans(m , 1);
        for(int i = 0 ; i < 32 ; i++){
            int mask = (1 << i);
            if(mask & (n))
                nums.push_back(mask);
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = queries[i][0] ; j <= queries[i][1] ; j++)
                ans[i] = (1ll * ans[i] * nums[j]) % mod;
        }
        return ans;
    }
};