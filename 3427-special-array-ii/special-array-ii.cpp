class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> interval = {0};
        vector<bool> ans;
        for(int i = 0 , j = 1 ; j < n ; j++){
            if(nums[j] % 2 == nums[j - 1] % 2)
                i++;
            interval.push_back(i);
        }
        for(auto it : queries)
            ans.push_back(interval[it[0]] == interval[it[1]]);
        return ans;
    }
};