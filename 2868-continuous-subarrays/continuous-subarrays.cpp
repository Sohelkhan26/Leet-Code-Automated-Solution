class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        map <int,int> freq;
        for(int left = 0 , right = 0 ; right < n ; right++){
            freq[nums[right]]++;
            while(freq.rbegin() -> first - freq.begin() -> first > 2){
                if(--freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};

/*
Input:
Given a array , find number of subarray's such that absolute difference between minimum and maximum value is <= 2
As we are required to find each possible subarray and we obviously can't apply brute force because n <= 10^5 we have to consider sliding window.
Implementation was quite tough. Map was used in a new way. Keys in maps are sorted. If the difference between max and min is <= 2 we add number of subarrays in the range [left , right] which is [right - left + 1] , otherwise we have to shrink the window.
*/