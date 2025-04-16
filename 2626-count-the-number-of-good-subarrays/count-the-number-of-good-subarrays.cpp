class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size() , samePair = 0;
        long long ans = 0;
        unordered_map <int,int> all;
        for(int left = 0 , right = 0 ; right < n ; right++){
            samePair += (all[nums[right]]++);
            while(samePair >= k){
                ans += (n - right);
                samePair -= --all[nums[left++]];
            }
        }
        return ans;
    }
};

/*
Standard sliding window technique. When a number is added to a subarray it increases pair count by it's previous count i.e: all[i] same goes for when it is removed.
Find the largest index 'j' such that the array is "bad", for every number added later, the subarray will be good, so add (n - j). now shrink the window.
*/