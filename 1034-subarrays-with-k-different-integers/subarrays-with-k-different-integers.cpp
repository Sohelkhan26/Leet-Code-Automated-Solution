class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size() , ans = 0 , valid = 0;
        unordered_map <int,int> window;
        for(int left = 0 , right = 0 ; right < n ; right++){
            if(++window[nums[right]] == 1)
                k--;
            if(k < 0){
                if(--window[nums[left++]] == 0)
                    k++;
                valid = 0;
            }
            if(k == 0){
                while(window[nums[left]] > 1)
                    --window[nums[left++]] , valid++;
                ans += (valid + 1); // 1 for smallest window that has k distinct elements
            }
        }
        return ans;
    }
};