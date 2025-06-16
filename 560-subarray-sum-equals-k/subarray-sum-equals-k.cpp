class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> prev;
        int n = nums.size() , ans = 0 , sum = 0;
        prev[0] = 1;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            if(prev.contains(sum - k))
                ans += prev[sum - k];
            prev[sum]++;
        }
        return ans;
    }
};