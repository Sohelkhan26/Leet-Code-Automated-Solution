class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int prevMax = nums[0] , ans = 1 , n = nums.size();
        for(int i = 1 ; i < n ; i++)
            if(nums[i] >= prevMax)
                prevMax = nums[i] , ans++;
        return ans;
    }
};

/*
Whenever a dip occurs, we have to remove the subarray and replace it with the max of the subarray. 
But we have to keep subarray as short as possible. 
our next numbers should be >= prevMax to maintain non-decreasing property.
Whenever there is otherwise, we merge it with our previous MaxValue and replace it with the maxValue.
*/