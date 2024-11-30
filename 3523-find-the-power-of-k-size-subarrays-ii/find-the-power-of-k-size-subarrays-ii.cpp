class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        for(int right = 0 , consecutive = 1 ; right < nums.size() ; right++){
            if(right != 0 and nums[right] == nums[right - 1] + 1)
                consecutive++;
            else consecutive = 1;
            if(right + 1 >= k) // accounts for the fact that the index is 0 based
                ans.push_back(consecutive >= k ? nums[right] : -1); // To form a valid window at least k values should be consecutive
        }
        return ans;
    }
};
/*
Whenever we encounter a consecutive element, just increment the count.
If count reaches window size 'k' or greater means you have good window.
If previous element is not consecutive, just reset the counter.
*/