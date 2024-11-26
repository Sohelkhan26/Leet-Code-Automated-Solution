/*
Make the maximum number of an partition as small as possible.
The minimum number as small as possible.
sort the array. find difference of consecutive elements. For eny two elements if the difference is smallest that's where nums should be partitioned.
*/
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int diff = INT_MAX , n = nums.size();
        for(int i = 1 ; i < n ; i++)
            diff = min(diff , nums[i] - nums[i - 1]);
        return diff;
    }
};