class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int n = sqrt(r);
        vector<bool> vis(n + 1 , true);
        vector<int> primes;
        for(int i = 2 ; i <= n ; i++)
            if(vis[i]){
                primes.push_back(i);
                for(int j = i * i ; j <= n ; j += i)
                    vis[j] = false;
            }    
        int prime = 0;
        for(int i : primes){
            int special = i * i;
            if(special >= l and special <= r)
                prime++;
        }
        return r - l + 1 - prime;
    }
};  