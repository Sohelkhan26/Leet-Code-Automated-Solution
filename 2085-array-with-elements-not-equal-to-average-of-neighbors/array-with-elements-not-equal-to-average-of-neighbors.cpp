class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int start = 0 , n = nums.size() , end = n - 1;
        vector <int> ans(n);
        for(int i = 0 ; i < n ; i++){
            if(i % 2 == 0)
                ans[i] = nums[end--];
            else ans[i] = nums[start++];
        }
        return ans;
    }
};