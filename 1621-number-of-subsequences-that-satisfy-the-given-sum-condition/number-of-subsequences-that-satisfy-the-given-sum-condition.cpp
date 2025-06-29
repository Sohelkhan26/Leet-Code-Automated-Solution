class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int ans = 0 , n = nums.size() , mod = 1e9 + 7 , left = 0 , right = n - 1;
        vector <int> power(n + 1 , 1);
        for(int i = 1 ; i <= n ; i++)
            power[i] = (1ll * power[i - 1] * 2) % mod;
        while(left <= right){
            if(nums[left] + nums[right] > target)
                right--;
            else 
                ans = (0ll + ans + power[right - left++]) % mod;
        }       
        return ans;
    }
};

/*
Fix a min or max and binary search the maximum other element could be such that sum <= target?
will sorting pose a problem to the problem description? I think not.
3,4,7 is same as 7,4,3 we are only concerned about the max and min of the subsequence, right?
This was the right approach, but counting number of subsequence possible for the current window is the place where I messed up.
For index 'left' find max possible 'right' index
Now for each element in range[left + 1 .. right] we can either include or not include it. Note that minimum element must be included , so total subseq = 2 ^ (right - left) not the usual 2 ^ (right - left + 1) -> this way it's not guaranteed that min element is nums[left]
*/