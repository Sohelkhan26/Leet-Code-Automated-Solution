class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int ans = 0 , sub = 0;
        for(int &n : nums){
            sub = (sub == 0 ? n : sub & n);
            ans += (sub == 0);
        }
        return max(1 , ans);
    }
};

/*
And value decreases or stays the same for every element added.
Min subarray value is AND of whole array.
If minVal is not zero, then some subarray or the entire array AND values is that min Value.
If some subarray AND is minValue , subarray built from rest of the element can't be <= minValue
So, answer = 1. 
*/