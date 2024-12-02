class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = accumulate(nums.begin() , nums.end() , 0) , ans = INT_MIN;
        multiset <int> seen(nums.begin() , nums.end());
        for(int outlier : nums){
            int temp = sum - outlier;
            if(temp % 2 == 0){
                seen.erase(seen.find(outlier));
                if(seen.contains(temp / 2))
                    ans = max(ans , outlier);
                seen.insert(outlier);
            }
        }
        return ans;
    }
};