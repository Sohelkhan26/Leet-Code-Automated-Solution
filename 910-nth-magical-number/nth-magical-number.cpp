class Solution {
public: 
    int nthMagicalNumber(int n, int a, int b) {
        long long low = min(a , b) , high = 1e14 , mid , ans;
        int mod = 1e9 + 7 , gcd = __gcd(a , b) , lcm = (1ll * a * b) / gcd;
        while(low <= high){
            mid = low + (high - low) / 2;
            long long count = (mid / a) + (mid / b) - (mid / lcm);
            if(count >= n)
                ans = mid , high = mid - 1;
            else low = mid + 1;
        }
        return ans % mod;
    }
};

/*
Interesting problem. Obviously n is 1e9 too big to linear search. 
Binary search or math is the only option. Since this is a programming problem let's keep math minimal. 
Observation: first magical number is min(a , b)
There could be number divisible by both a and b
This could create overcounting. handling these two facts solve the problem.
lcm(a , b) is the smallest value divisible by both a & b
So, every number divisible by both a & b must be divisible by lcm(a , b)
x / y gives us count of numbers in range [1..x] such that x % y == 0
Recall that to count numbers divisible by 5 in range x is:
x / 5 + x / 25 + x / 125 ... until denominator exceeds x
What's the upper bound for the binary search? it's n * min(a , b)
Don't know how. 1e14 works just fine. Be wary of overflow.
*/