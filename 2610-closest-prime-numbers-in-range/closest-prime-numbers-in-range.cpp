class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector <int> prime , ans = {-1 , -1};
        int n = right , diff = INT_MAX;
        vector<bool> isPrime(n + 1, true);

        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for(int i = left ; i <= right ; i++)
            if(isPrime[i])
                prime.push_back(i);
        for(int i = 1 ; i < prime.size() ; i++){
            int gap = prime[i] - prime[i - 1];
            if(gap < diff){
                diff = gap;
                ans = {prime[i - 1] , prime[i]};
            }
        }
        return ans;
    }
};