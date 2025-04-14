class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size() , leftMax = -1 , ans = 0;
        vector <int> rightMin(n);
        rightMin[n - 1] = nums[n - 1];
        for(int i = n - 2 ; i >= 0 ; i--)
            rightMin[i] = min(rightMin[i + 1] , nums[i]);
        for(int i = 0 ; i < n ; i++){
            leftMax = max(leftMax , nums[i]);
            if(leftMax <= rightMin[i + 1])
                return i + 1;
        }
        return ans;
    }
};

/*
Although the intuition is not hard, it's quite tricky to implement and visualize.
It seemed that the fact "smallest length of left is ambiguous". But it is not.
Preprocess the array to efficiently find the minimum element on the right subarray.
Keep track of maximum element as we are going from left to right. If we find a maximum element that is less than or equal to the largest element on the right subarray, we have found the desired left subarray, as the index is 0 based, return i + 1.
*/