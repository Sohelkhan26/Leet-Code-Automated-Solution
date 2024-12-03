class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long goodPairs = 0;
        unordered_map <int,int> pairCount;
        for(int i = 0 ; i < n ; i++)
            goodPairs += pairCount[nums[i] - i]++; // goodPairs += i - pairCount[nums[i] - i]++;
        return 1ll * n * (n - 1) / 2- goodPairs;
    }
};

/*
Observation : j - i != nums[j] - nums[i] can be converted to
            nums[i] - i = nums[j] - j
And it is easier to find good Pairs then bad pairs
So we keep a map to keep track of same nums[i] - i values. Once we encounter a same value it adds one pair to the goodPair.
we found all pairs using 1ll * n * (n - 1) / 2 extra 1ll is used for type casting to long long.
Instead we could have used total += i in the for loop.
Everytime a number is introduced a pairs is formed. And the count of number can be determined by the index.
4 1 3 4
index : 0 1 2 3
4 adds 0 pair
1 adds 1 pair
2 add 2 pair = (0 , 2) (1 2)
and so on
*/