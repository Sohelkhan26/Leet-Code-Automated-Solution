class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size() , mask = 1 << n , sum = 0;
        for(int i = 1 ; i < mask ; i++){
            int subset = 0;
            for(int j = 0 ; j < n ; j++){
                if((i >> j) & 1)
                    subset ^= nums[j];
            }
            sum += subset;
        }
        return sum;
    }
};