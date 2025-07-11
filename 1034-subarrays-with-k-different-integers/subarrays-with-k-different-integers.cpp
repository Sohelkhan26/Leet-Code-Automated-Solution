class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        auto solve = [&](int K){
            int ans = 0;
            unordered_map <int,int> window;
            for(int left = 0 , right = 0 ; right < n ; right++){
                window[nums[right]]++;
                while(window.size() > K){
                    if(--window[nums[left]] == 0)
                        window.erase(window.find(nums[left]));
                    left++;
                }
                ans += (right - left + 1);
            }
            return ans;
        };
        return solve(k) - solve(k - 1);
    }
};