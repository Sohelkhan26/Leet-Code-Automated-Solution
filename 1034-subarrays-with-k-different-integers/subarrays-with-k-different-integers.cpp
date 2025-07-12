class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> window; 
        int leftFar = 0 , leftNear = 0 , ans = 0 , n = nums.size();


        for(int right = 0 ; right < n ; right++){
            window[nums[right]]++;
            while(window.size() > k){
                if(--window[nums[leftNear]] == 0)
                    window.erase(nums[leftNear]);
                leftNear++;
                leftFar = leftNear;
            }
            while(window[nums[leftNear]] > 1)
                --window[nums[leftNear++]];
            if(window.size() == k)
                ans += (leftNear - leftFar + 1);
        }

        return ans;
    }
};
