class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        // sort(nums.begin() , nums.end());
        // int n = nums.size() , mod = 1e9 + 7;
        // long long ans = 0 , prefix = 0 , total = accumulate(nums.begin() , nums.end() , 0ll , [&](long long sum , int n){return sum + n * n;});
        // // i + 1 number of groups has nums[i] as max
        // // n - i number of groups has nums[i] as min
        // // 1st case is easy, contribution = nums[i] * nums[i] * nums[0]
        // // 2nd case maintains a total and prefix sum. total = sum(nums[i] * nums[i]) for all i
        // // contribution = (total - prefix) * nums[i]
        // for(int i = 0 ; i < n ; i++){
        //     prefix += (nums[i] * nums[i]);
        //     total -= prefix;
        //     ans = (ans + 1ll * (i + 1) * nums[i] * nums[i] * nums[0]) % mod;
        //     // ans = (ans + 1ll * (n - i - 1) * total * nums[i]);
        // }
        // return ans;
        sort(nums.begin() , nums.end());
        int n = nums.size() , mod = 1e9 + 7;
        long long ans = 0 , prefix = 0;
        for(int &curr : nums){
            // fix curr as maximum, it's contribution will be
            // curr * curr * (sum of all possible mins ending at x)
            // how to find sum efficiently? looping takes too much time.
            // 
            long long contribution = (1ll * (1ll * curr * curr) % mod * (prefix + curr)) % mod;
            ans = (ans + contribution) % mod;
            prefix = (2 * prefix + curr) % mod;
        }
        return ans;
    }
};

/*
number of non-empty group is too high n ^ 2
can't create every group let alone calc their power.
have to calculate contribution of every hero.
It can either act as max/min of the group. calc both contribution.
sort.
1,2,4
Taken from ChatGpt:

\U0001f9e0 Why 2 * prefix + x?
Step-by-step intuition:
There are 2^(i-1) subsets of the first i-1 elements.

Let’s call those subsets S1, S2, ..., Sk.

Now consider what happens when you include x = nums[i]:

\U0001f539 Existing subsets → generate 2× subsets:
You can form:

All previous subsets (without x)

All new subsets by adding x to each old subset

So number of subsets doubles.

\U0001f539 What about the min in new subsets?
Let’s break it into two cases:

Old subsets stay the same

Their min values stay the same → total contribution: prefix

New subsets with x added

For each old subset S, we form S' = S ∪ {x}

The new minimum becomes:

min(S') = min(min(S), x)

But here's the key trick:

Because the array is sorted, and x is the largest so far:

min(S') = min(S) → because x ≥ all previous nums

So:

Each new subset still contributes the same min(S)
→ So, same contribution as before = prefix

Thus:

new total min sum = prefix (old subsets) + prefix (new subsets) + x (for subset {x})

Final: prefix = 2 * prefix + x

\U0001f501 Why do we add x?
Because:

We add the new subset {x} alone.

min({x}) = x

So we add it once to the sum.
*/