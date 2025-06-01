class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hor, vector<int>& ver) {
        hor.emplace_back(1);
        hor.emplace_back(m);
        ver.emplace_back(1);
        ver.emplace_back(n);
        unordered_map <int,bool> diff;
        for(int i = 0 ; i < hor.size() ; i++)
            for(int j = 0 ; j < hor.size() ; j++)
                diff[abs(hor[j] - hor[i])] = true;
        
        int ans = 0 , mod = 1e9 + 7;
        for(int i = 0 ; i < ver.size() ; i++)
            for(int j = 0 ; j < ver.size() ; j++){
                int d = abs(ver[j] - ver[i]);
                if(i != j and diff.contains(d))
                    ans = max(ans , d);
            }
        return ans == 0 ? -1 : (1ll * ans * ans) % mod;
    }           
};