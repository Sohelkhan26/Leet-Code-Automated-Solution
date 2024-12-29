class Solution {
public: 
    int ans = 0;
    void solve(int i , vector<int> &nums , int target , int sum){
        if(i == nums.size()){
            if(target == sum)   
                ans++;
            return;
        } 
        solve(i + 1 , nums , target , sum + nums[i]);
        solve(i + 1 , nums , target , sum - nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(0 , nums , target , 0);
        return ans;
    }
};