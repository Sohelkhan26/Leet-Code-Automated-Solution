class Solution {
public:
    int getMaxLen(vector<int>& nums , int start = 0) {
        int n = nums.size() , ans = 0 , prev[2] = {start - 1 , INT_MAX};
        // prev[0] : earliest index where neg-number-count = even , prev[1] : earliest index where neg-number-count = odd
        bool odd = false;
        for(int i = start ; i < n ; i++){
            if(nums[i] == 0) // encounter of 0 forces to start over
                return max(ans , getMaxLen(nums , i + 1));
            odd = (nums[i] < 0 ? not odd : odd); // toggle
            prev[odd] = min(prev[odd] , i); // keep earliest one
            ans = max(ans , i - prev[odd]); // as we assigned prev[0] = start - 1 , it won't change in the future. and cause of prevous -1 , we don't need i - prev[odd] + 1. If we again encounter odd parity of neg-num-counter then subarray [prev[odd] , i) (non-inclusive) has even number of negative number. So, i - prev[odd] + 1 is not correct.
        }
        return ans;
    }
};
