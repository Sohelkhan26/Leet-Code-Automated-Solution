class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> intervals = {0};
        for(int inter = 0 , i = 1 ; i < nums.size() ; i++){
            if(nums[i] % 2 == nums[i - 1] % 2)
                inter++;
            intervals.push_back(inter);
        }
        vector<bool> ans;
        for(auto q : queries)
            ans.push_back(intervals[q[0]] == intervals[q[1]]);
        return ans;
    }
};