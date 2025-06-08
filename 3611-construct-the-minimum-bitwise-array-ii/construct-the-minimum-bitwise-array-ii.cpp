class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n , -1);
        for(int j = 0 ; j < n ; j++){
            for (int x = max(0, (int)(nums[j] - 1e6)); x <= nums[j] ; ++x)
                if((x | (x + 1)) == nums[j]){
                    ans[j] = x;
                    break;
                }
        }
        return ans;
    }
};