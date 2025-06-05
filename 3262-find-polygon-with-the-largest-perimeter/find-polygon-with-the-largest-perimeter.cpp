class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        vector <long long> prefix(n + 1);
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < n ; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        for(int i = n - 1 ; i >= 1 ; i--)
            if(prefix[i] > nums[i])
                return prefix[i + 1];
        return -1;
    }
};