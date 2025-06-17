class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map <int,vector<int>> mp;
        for(int i = 0 ; i < nums.size() ; i++)
            mp[nums[i]].push_back(i);
        int ans = 1;
        for(auto &[x , idx] : mp){
            int op = k , n = idx.size();
            for(int left = 0 , right = 1 ; right < n ; right++){
                while((idx[right] - idx[left] + 1) - (right - left + 1) > k)
                    left++;
                ans = max(ans, right - left + 1);
            }
        }
        return ans;
    }
};