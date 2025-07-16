class Solution {
public: 
    int nthMagicalNumber(int n, int a, int b) {
        long long low = min(a , b) , high = 1ll * n * min(a , b) , mid , ans;
        int mod = 1e9 + 7 , gcd = __gcd(a , b) , lcm = (1ll * a * b) / gcd;
        while(low <= high){
            mid = low + (high - low) / 2;
            int count = (mid / a) + (mid / b) - (mid / lcm);
            if(count >= n)
                ans = mid , high = mid - 1;
            else low = mid + 1;
        }
        return ans % mod;
    }
};