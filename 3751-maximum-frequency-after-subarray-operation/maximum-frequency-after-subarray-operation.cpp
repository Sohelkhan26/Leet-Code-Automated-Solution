class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans = 0 , n = nums.size();
        for(int fix = 1 ; fix < 51 ; fix++){
            if(fix == k)continue;
            int freq = 0 , maxFreq = 0;
            for(int &i : nums){
                freq += (i == fix ? 1 : i == k ? -1 : 0); 
                freq = max(0 , freq); // start anew
                maxFreq = max(maxFreq , freq);
            }
            ans = max(ans , maxFreq);
        }
        return ans + count(nums.begin() , nums.end() , k);
    }
};
/*
We can select x as positive or negative.
Kadene is used to find maximum subarray sum. When subarray sum falls below 0, start a new subarray there.
Keep track of maximum sum everytime.
Since nums[i] <= 50, we can fix a number. We will try to make every number to this fixed number.
If number is k then we can't save it. It will be some other number after modification.
Pretty much the same. Count gain of subarray. When gain falls below 0, reset it 0(meaning it's more profitable to start a new subarray here). Track max gain and add with count of k.
Adding count of k at the end may seem ambiguous
nums = [2,4,4,4,2,4,4,4,2] , k = 2
max gain is earned from [1..n-1] subarray, we could have gain = 6 but middle 2 makes gain = 5
So, adding count(k) at the end evens it out.
*/