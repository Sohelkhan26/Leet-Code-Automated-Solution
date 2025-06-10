class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size() , remove = 0;
        for(int i = 0 , j = n / 2 ; i < n / 2 and j < n ; ){
            if(nums[i] < nums[j])
                remove += 2 , i++ , j++;
            else j++;
        }
        return n - remove;
    }
};
/*
removal order matters.
1,1,2,2,3,3
1-2 not optimal
1-3 not optimal either
1-2,2-3,1-2 optimal cant be just greedy.
DP? for each index, we can have atmost n / 2 choice.
*/