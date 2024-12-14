class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        return max(0 , *max_element(nums.begin() , nums.end()) - k - *min_element(nums.begin() , nums.end()) - k);
    }
};

/*
Try to be gready. Add maximum k to smallest value and minimum k to largest value.First I thought of greedy approach but then I thought what if the numbers in between doesn't lie in the range [newMin , newMax](after operation) ? 
Every other numbers can be turned in between the range [newMin , newMax] by adding [-k , +k] so we don't need to worry about them. 
so return max(0 , max - k - (min + k))
*/