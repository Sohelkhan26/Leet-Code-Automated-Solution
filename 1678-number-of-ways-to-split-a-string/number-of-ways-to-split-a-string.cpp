class Solution {
public:
    const int mod = 1e9 + 7;
    int numWays(string s) {
        int one = count(s.begin() , s.end() , '1') , n = s.size();
        if(one % 3 != 0)
            return 0;
        if(one == 0)
            return (1ll * (n - 2) * (n - 1) / 2) % mod;
        int div = one / 3 , ans = 1 , cnt = 0 , mul = 0;
        for(char &c : s){
            cnt += (c == '1');
            if(cnt > div){
                ans = (1ll * ans * mul) % mod;
                cnt = 1 , mul = 0;
            }
            if(cnt == div)
                mul++;
        }
        // if(mul != 0)
        //     ans = (ans * mul) % mod;
        return ans;
    }
};