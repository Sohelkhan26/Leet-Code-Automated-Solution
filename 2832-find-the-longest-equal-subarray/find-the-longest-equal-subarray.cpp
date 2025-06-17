class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map <int,vector<int>> mp; // nums[i] -> i
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
/*
4 -> 1,3,5,9,13 , k = 3 or whatever
the sum of gap in-between indices can be at most k (k element can be deleted)
If sum-gap exceeds k, shrink window.
idx[right] - idx[left] + 1 -> operation needed
But, we have (right - left + 1) -> elements present.
So, operation = (idx[right] - idx[left] + 1) - (right - left + 1)
              = (idx[right] - idx[left]) - (right - left) is the desired window.
*/