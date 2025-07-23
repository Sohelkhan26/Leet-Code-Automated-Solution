class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size() , m = b.size();
        long long base = 109 , mod = 1e9 + 9 , aHash = 0 , bHash = 0 , power = 1;
        for(char &c : b){
            bHash = (bHash * base + (c - 'a' + 1)) % mod;
            power = (power * base) % mod;
        }
        for(int i = 0 ; i < 2 * m + n ; i++){
            int j = i % n;
            aHash = (aHash * base + (a[j] - 'a' + 1)) % mod;
            if((i + 1) > m)
                aHash = (aHash - (1LL * (a[(i - m) % n] - 'a' + 1) * power) % mod) % mod;
            if(aHash < 0)
                aHash += mod;

            if(aHash == bHash) 
                return (i + 1 + n - 1) / n;
        }
        return -1;
    }
};