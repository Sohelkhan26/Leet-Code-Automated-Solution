class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size() , maxLeft = nums[0];
        vector <int> suff(n);
        suff[n - 1] = nums[n - 1];
        for(int i = n - 2 ; i >= 0 ; i--)
            suff[i] = min(suff[i + 1] , nums[i]);
        int ans = 0;
        for(int i = 1 ; i < n - 1 ; i++){
            if(maxLeft < nums[i] and nums[i] < suff[i + 1])
                ans += 2;
            else if(nums[i - 1] < nums[i] and nums[i] < nums[i + 1])
                ans++;
            maxLeft = max(maxLeft , nums[i]);
        }
        return ans;
    }
};