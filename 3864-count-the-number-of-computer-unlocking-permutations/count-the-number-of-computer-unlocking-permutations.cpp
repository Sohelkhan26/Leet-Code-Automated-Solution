class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mod = 1e9 + 7 , n = complexity.size() , ans = 1;
        for(int i = 1 ; i < n ; i++){
            ans = (1ll * ans * i) % mod;
            if(complexity[i] <= complexity[0])
                return 0;
        }
        return ans;
    }
};