class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0 , n = nums1.size() , m = nums2.size();
        if(n % 2 == 1)
            for(int i : nums2)
                ans ^= i;
        if(m % 2 == 1)
             for(int i : nums1)
                ans ^= i;
        return ans;
    }
};