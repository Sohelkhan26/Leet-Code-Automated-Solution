class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n = nums.size() , sum = 0;
        for(int i = 0 ; i < n ; i++){
            int left = i - k >= 0 ? nums[i - k] : -1;
            int right = i + k < n ? nums[i + k] : -1;
            sum += nums[i] * (nums[i] > left and nums[i] > right);
        }
        return sum;
    }
};