class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long low = 1 , high = 2LL * (1e9) , mid , ans;
        auto lcm = [](long long a , long long b) -> long long{
            return (1LL * a * b) / (__gcd(a , b));
        };
        long long ab = lcm(a , b) , ac = lcm(a , c) , bc = lcm(b , c) , abc = lcm(a , bc);
        while(low <= high){
            mid = low + (high - low) / 2;
            long long count = (mid / a) + (mid / b) + (mid / c) - (mid / ab) - (mid / ac) - (mid / bc) + (mid / abc);
            if(count >= n)
                ans = mid , high = mid - 1;
            else low = mid + 1;
        }
        return ans;
    }
};