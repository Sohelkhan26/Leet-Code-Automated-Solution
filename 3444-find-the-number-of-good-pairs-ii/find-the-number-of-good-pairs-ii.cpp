class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        unordered_map <int,int> freq;
        for(int &i : nums2)
            freq[i * k]++;
        for(int &n : nums1){
            for(int i = 1 ; i * i <= n ; i++){
                if(n % i != 0)
                    continue;
                ans += freq[i];
                if(i != n / i)
                    ans += freq[n / i];
            }
        }
        return ans;
    }
};
/*
Find pairs of nums1[i] % (nums[j] * k) == 0.
Precompute nums2. By storing frequency of (nums[j] * k) in a map.
For every number 'n' in nums1, how do we find count(nums2[i]) that divides n? Iterate over the map? Then it's the same brute force.
For every divisor of 'n' if it's present in the map, then nums1[i] % (nums[j] * k) == 0

*/ 