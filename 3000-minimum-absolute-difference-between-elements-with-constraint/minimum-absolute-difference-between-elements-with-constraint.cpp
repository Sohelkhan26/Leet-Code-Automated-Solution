class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set <int> seen;
        int n = nums.size() , ans = INT_MAX;
        for(int i = x ; i < n ; i++){
            seen.insert(nums[i - x]);
            auto it = seen.lower_bound(nums[i]);
            if(it != seen.end())    
                ans = min(ans , abs(*it - nums[i]));
            if(it != seen.begin())
                ans = min(ans , abs(*prev(it) - nums[i]));
        }
        return ans;
    }
};