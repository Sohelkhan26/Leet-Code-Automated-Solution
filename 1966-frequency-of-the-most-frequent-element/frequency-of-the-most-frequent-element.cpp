class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size() , ans = 0;
        sort(nums.begin() , nums.end());
        long long sum = 0;
        for(int left = 0 , right = 0 ; right < n ; right++){
            sum += nums[right];
            while(1ll * (right - left + 1) * nums[right] - sum > k)
                sum -= nums[left++];
            ans = max(ans , right - left + 1);
        }
        return ans;
    }
};

/*
in one operation, any element can be increased by 1.
return max freq of an element after performing k operation. Seems like I have seen this problem before.
 
If within k operation, we can't make any new highest frequency element?
100,100,100,2,2,1,0 , k = 3
ans = 4, so this kind of greedy don't work.

each element -> group
within k moves, merge two+ groups fully/partially.
groups with min diff should be merged.
Binary search with greedy? merge adjacent groups?
I was on the point but slightly wrong. I had an idea about sliding window, but overthinked about how I would implement it.
We want to merge adjacent groups. want to make every element in the window equal to nums[right] 
so (right - left + 1) * nums[right] is our target
but currently we have sum
we need at least theird difference move. If we don't have this many move shrink the window.
*/