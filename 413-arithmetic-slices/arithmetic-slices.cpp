class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size() , subarray = 0 , ans = 0;
        for(int i = 1 ; i < n - 1 ; i++){
            if(nums[i] - nums[i - 1] == nums[i + 1] - nums[i]) // we can add this element to our existing arithmetic subarray.
                ans += ++subarray;
            else subarray = 0;
        }
        return ans;
    }
};

/*
Adding the current element to the existing arithmetic sequence will create "subarray" additional combinations of new arithmetic slices.
Need at least 3 elements, so searching range should be [1 , n - 2]
*/