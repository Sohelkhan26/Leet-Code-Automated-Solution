class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set <int> seen = {0};
        int n = nums.size() , prefix = 0 , ans = 0;
        for(int &x : nums){
            prefix += x;
            if(seen.contains(prefix - target)){
                ans++;
                seen.clear();
            } 
            seen.insert(prefix);
        }
        return ans;
    }
};

/*
prefix sum sliding window maybe?
But does that ensure maximum subarray count ? 
non-overlapping condition?
I think greedy will work. Don't have to reduct the len of subarray or anything. Shorter and bigger subarray will only add 1 to answer if found.
It's like that removing k elements such that distinct element of an array is maximum. Removing distinct character is same as removing multiple occurance of an number, the decrease in answer is 1.
prefix sum may not be distinct cause of negative number,
*/