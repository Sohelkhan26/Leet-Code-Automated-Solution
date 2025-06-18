class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector <int> have(32);
        for(int &n : nums)
            have[(int)log2(n)]++;
        int missing = 32 , ans = 0;
        for(int i = 0 ; i < 31 ; i++){
            int bit = (1 << i);
            if(target & bit){
                if(have[i]) // if we have that power of 2 in nums use it otherwise we will have to make it in future by breaking
                    have[i]--;
                else 
                    missing = min(missing , i); // we only need to store the minimum power of 2 needed. In future if we find a larger power of 2, all in between power-of-2 can be covered up.
            }
            if(have[i] and i > missing){
                have[i]--;
                ans += (i - missing);
                missing = 32; // reset
            }
            have[i + 1] += have[i] / 2; // if we don't need this power of 2, can use it in future.
        }
        return missing < 32 ? -1 : ans;
    }
};
/*
all elements power of 2
in one operation select an element > 1
remove it and add two element / 2 at the end
return min operation needed to find a subsequence whose sum == target

Since ever element is power of 2
and target has to be sum of power of 2
we have to find each power of two in target in nums array.
If that power of 2 is not present in nums array, we have to make it by breaking a larger power of 2.
Important observation is:
we have to add "two" nums[i] / 2
64 , 32 , 16 , 8 , 4 , 2 , 1
32 , 32 -> 16,16
16 -> 8 , 8
8 -> 4 , 4
4 -> 2 , 2
we can keep one nums[i] / 2 and use another to cover up smaller power of 2
if we break 64 we can cover all 32..1 if they are not present
*/