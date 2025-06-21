class Solution {
public:
    long long sumOfLargestPrimes(string s) {
        vector<long long> primes;
        auto prime = [&](long long n){
            if(n == 1)
                return false;
            for(long long i = 2 ; i * i <= n ; i++)
                if(n % i == 0)
                    return false;
            return true;
        };

        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            for(int len = 1 ; i + len <= n ; len++){
                long long num = stol(s.substr(i , len));
                if(prime(num))
                    primes.push_back(num);
            }
        }

        long long ans = 0;
        sort(primes.rbegin() , primes.rend());
        primes.erase(unique(primes.begin() , primes.end()) , primes.end());
        int m = primes.size();
        for(int i = 0 ; i < min(3 , m) ; i++)
            ans += primes[i];
        return ans;
    }
};