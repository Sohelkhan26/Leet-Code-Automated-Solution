class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size() , -1);
        for(int j = 0 ; j < nums.size() ; j++){
            int n = nums[j];
            for(int i = 31 ; i >= 0 ; i--){
                int a = 0;
                if((1 << i) & n)
                    a = (n & ~(1 << i));
                if((a | (a + 1)) == n){
                    ans[j] = a;
                    break;
                }
            }
        }
        return ans;
    }
};