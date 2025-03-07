class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size() , left = 0 , right = n - 1;
        vector <int> ans(n);
        for(int i = 0 ; i < n ; i++){
            if(nums[i] < pivot)
                ans[left++] = nums[i];
            if(nums[n - i - 1] > pivot)
                ans[right--] = nums[n - i - 1];
        }
        while(left <= right)
            ans[left++] = pivot;
        return ans;
    }
};