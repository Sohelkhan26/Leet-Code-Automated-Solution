class Solution {
public:
    int findNthDigit(int n) {
        auto digitCountUpTo = [&](int n){
            long long count = 0 , len = 1 , start = 1;
            while(n >= start){
                long long end = min(1ll * n , start * 10 - 1); // n may be in the middle of the range.
                // 3 digit numbers [100,999] but 'x' count be 888
                count += (end - start + 1) * len;
                len++ , start *= 10;
            }
            return count;
        };
        int low = 1 , high = INT_MAX , mid , ans = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(digitCountUpTo(mid) >= n){
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        int i = digitCountUpTo(ans - 1); // digit in [1..ans - 1] , ans contains [ans - 1 .. n] digits.
        string s = to_string(ans);
        return s[n - i - 1] - '0'; // 1 indexed so -1 
    }
};

/*
Awesome problem. We decide to find the minimum number 'ans' such that total number of digits from [1..x] 
is >= n Meaning find 'ans' such that the digit is present in that number.
Now for Math part: For a number 'x' how to calculate the number of digit?
Find digit-count of 'x'. Say it's 'y', now find total digits in:
1 digit numbers have : 1-9 digits
2 digit numbers have : 10-99 = (99-9) * 2 = 180 digits
3 digit numbers have : 100-999 = (999 - 99) * 3 = 2700 digits
y digit numbers have : ....
if start is 1 then end is 9 = (10 - 1) , digits = (9 - 1 + 1) * 1 = 9 digits
if start is 10 then end is 99 = (10 * 10 - 1) , digits = (99 - 10 + 1) * 2 = 180 digits
End can be in the middle depending on the 'n'
*/