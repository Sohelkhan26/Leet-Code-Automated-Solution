class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map <long , long> prev;
        for(int i : nums){
            int currGcd = __gcd(i , k);
            for(auto &[prevGcd , count] : prev)
                if((prevGcd * currGcd * 1ll) % k == 0)
                    ans += count;
            prev[currGcd]++;
        }
        return ans;
    }
};

/*
For the product a * b to be divisible by k,
the product a * b must cover all primes of k with at least the same powers.
The gcd(a, k) tells you which prime factors of k are present in a, and how many times.
a = 12, k = 8

12 = 2^2 * 3, 8 = 2^3

gcd(12, 8) = 4 = 2^2

GCD tells us a contains 2^2 towards matching the 2^3 in k.
Multiplying GCDs = Combining Contributions.
gcd(a, k) * gcd(b, k) % k == 0
then their combined contributions fully cover all prime factors of k
*/