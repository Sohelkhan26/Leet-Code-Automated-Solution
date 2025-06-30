class Solution {
public:
    int longestWPI(vector<int>& nums) {
        int n = nums.size() , ans = 0 , prefix = 0;
        unordered_map <int,int> seen;
        for(int i = 0 ; i < n ; i++){
            prefix += (nums[i] > 8 ? 1 : -1);
            if(prefix > 0)
                ans = i + 1;
            else{
                if(seen.contains(prefix - 1))
                    ans = max(ans , i - seen[prefix - 1]);
                seen.insert({prefix  , i}); // only store the first appearance. [8,10,6,16,5]
            }
        }
        return ans;
    }
};
/*
Interval is consecutive days?
elements >= 9 -> 1
others, -> -1?
find len of longest subarray such that sum of subarray >= 1? Kadene? if subarray sum < 0 discard? Or sliding window? shrink when sum <= 0
Sliding window seems too easy, right?
Yeah, typical one don't work.
Kadene won't work too. Prefix sum sliding window maybe?
Prefix sum with two loops should pass?
Indeed passed cause of low constraints. But barely. 2.2 seconds

This solution came to my mind, but i thought for a prefix, simply 
checking prefix - 1 is not enough. We have to check prefix - i(i in range [1..prefix - 1]) but, that is not the case. Prefix - x (x > 2) will result in shorter good interval. because we have to pass (prefix - 1) in the process.
*/