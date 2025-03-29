class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int low = 0 , high = maxSum , mid , ans = -1;
        auto check = [&](int a){
            long long res = 0 , b = max(a - index , 0);
            res += (a + b) * (a - b + 1) * 1ll / 2;
            b = max(a - ((n - 1) - index) , 0);
            res += (a + b) * (a - b + 1) * 1ll / 2;
            return (res - a) <= maxSum;
        };
        while(low <= high){
            mid = low + (high - low) / 2;
            if(check(mid)){
                ans = mid;
                low = mid + 1;
            }else high = mid - 1;
        }
        return ans + 1;
    }
};

/*
We first do maxSum -= n,
then all elements needs only to valid A[i] >= 0 (For this reason return ans + 1)

We binary search the final result between left and right,
where left = 0 and right = maxSum.

For each test, we check minimum sum if A[index] = a.
It's arithmetic sequence on the left of A[index] with difference is 1.
It's also arithmetic sequence on the right of A[index] with difference is -1.

On the left, A[0] = max(a - index, 0), {because we subtracted 1 from each index , we don't need to think about the condition index > a}
On the right, A[n - 1] = max(a - ((n - 1) - index), 0), there are n - i - index elements on the right.

The sum of arithmetic sequence {b, b+1, ...a-1, a},
equals to (a + b) * (a - b + 1) / 2.
(a - b + 1) is the length of the arithmetic sequence. Since ours arithmetic sequence has a difference of 1 we used this. Generally it is denoted as n.
*/