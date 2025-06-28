class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSum = INT_MAX , maxSum = INT_MIN , n = nums.size() , sum1 = 0 , sum2 = 0 , total = 0;
        for(int &x : nums){
            sum1 += x , sum2 += x;
            maxSum = max(maxSum , sum1);
            minSum = min(minSum , sum2);
            if(sum1 < 0)
                sum1 = 0;
            if(sum2 > 0)
                sum2 = 0;
            total += x;
        }
        return maxSum > 0 ? max(maxSum , total - minSum) : maxSum;
    }
};