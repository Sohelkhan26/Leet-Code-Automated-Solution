class Solution {
public:
    int maxPow(int a , int b , int mod){
        if(b == 0)
            return 1;
        int ans = maxPow(a , b / 2 , mod);
        ans = (ans * ans) % mod;
        if(b % 2)
            ans = (ans * a) % mod;
        return ans;
    } 
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector <int> ans;
        for(int i = 0 ; i < variables.size() ; i++){
            auto it = variables[i];
            int a = it[0] , b = it[1] , c = it[2] , m = it[3];
            int res = maxPow(a , b , 10);
            res = maxPow(res , c , m);
            if(res == target)
                ans.push_back(i);
        }
        return ans;
    }
};