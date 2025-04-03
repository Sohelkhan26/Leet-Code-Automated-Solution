class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int prev = -1 , sum = 0 , ans = 0 , n = nums.size();
        for(int i : nums){
            if(i > prev)
                sum += i , prev = i;
            else ans = max(ans , sum) , sum = prev = i;
        }
        return max(ans , sum);
    }
};