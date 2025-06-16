class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> prev;
        int n = nums.size() , ans = 0 , prefix = 0;
        prev[0] = 1; // this is used for the first prefix sum = k 
        for(int i = 0 ; i < n ; i++){
            prefix += nums[i];
            if(prev.contains(prefix - k))
                ans += prev[prefix - k];
            prev[prefix]++;
        }
        return ans;
    }
};

/*
Intuition is pretty straightforward.
If we encounter the same prefix-sum later in the array, that means, middle subarray sum is 0
That fact is used here. If we countered "prefix - k" sum in the past, that means the middle subarray sum = prefx(current prefix sum) - (prefix - k) = k 
*/