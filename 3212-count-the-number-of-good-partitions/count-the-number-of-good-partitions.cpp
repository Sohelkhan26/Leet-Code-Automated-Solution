class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size() , ans = 1 , mod = 1e9 + 7;
        unordered_map <int,int> last;
        for(int i = 0 ; i < n ; i++)
            last[nums[i]] = i;
        for(int start = 0 , maxRight = 0 ; start < n ; start++){
            if(start > maxRight) // can start new subarray or merge with previous subarray.
                ans = (1ll * ans * 2) % mod;
            maxRight = max(maxRight , last[nums[start]]);
        }
        return ans;
    }
};

/*
One easy Hard problem.
Given an array, have to partition into 1+ subarray such that same element don't belong to more than 1 subarray.(have to partition the whole array without leaving any element).

return number of ways to do that.
If a element occurs twice or more, all elements between the first and last occurance must be in the same subarray(to satisfy condition: no 2 subarray can have same element). This way suppose there are 'n' maximum subarray.

And we can merge one subarray with previous subarray or start it as independent. So, each subarray has 2 possibility. so ans *= 2

in other words total ways = 2 ^ (n - 1)
*/