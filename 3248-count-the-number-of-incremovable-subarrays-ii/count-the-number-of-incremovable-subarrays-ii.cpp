class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        vector <int> increasing = {nums.back()}; // store longest increasing subarray from the end
        for(int i = n - 2 ; i >= 0 and nums[i] < nums[i + 1] ; i--)
            increasing.push_back(nums[i]);
        reverse(increasing.begin() , increasing.end()); 
        int m = increasing.size();
        if(n == m) // full array is increasing. so removing any subarray fulfills the criteria
            return 1ll * n * (n + 1) / 2; // total number of subarray in a array of length n
        long long ans = increasing.size() + 1; // suppose j is the index where we stopped. We can remove all subarray ending at [j..n] and [j + 1 .. n] will be still increasing. empty array is valid too.
        n -= m;
        for(int i = 0 , prev = -1 ; i < n and nums[i] > prev ; i++){
            prev = nums[i];
            ans += increasing.end() - upper_bound(increasing.begin() , increasing.end() , nums[i]) + 1;
// we found a strictly greater element than nums[i] , so all subarray in the middle can be deleted. Increasing array is ascending. So, we can include every element in the middle subarray too.
        }
        return ans;
    }
};

/*
We have to ensure suffix + prefix is sorted after removing a subarray. and count such subarrays.
suppose we found a array [j..n] which is strictly increasing. Store this array.
we can remove [0..j-1] and [j..n] is increasing already. this is one subarray.
for every element in [j..n] subarray count increase by 1.
So, ans = size of [j..n]
Now starting from the beginning, for every element nums[i] we can find a strictly greater element in the previous array. Suppose this index is j , [j + 1..n] is also strictly increasing, ensured before.
[i..j] can be removed and [0..i] + [j + 1..n] will still be increasing.
and for every element in [j + 1 .. n] subarray count increases.
*/