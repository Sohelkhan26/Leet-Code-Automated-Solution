class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 1 , dp1 = 1 , dp2 = 1 , n = nums1.size() , t11 , t12 , t21 , t22;
        // dp1 -> max path ending at nums1[i] , dp2 -> at nums2[i]
        for(int i = 1 ; i < n ; i++){
            t11 = (nums1[i - 1] <= nums1[i] ? dp1 + 1 : 1);
            t12 = (nums1[i - 1] <= nums2[i] ? dp1 + 1 : 1);
            t21 = (nums2[i - 1] <= nums1[i] ? dp2 + 1 : 1); // ends at nums1[i] so this will be used to update dp1 , prev = nums2[i - 1] , so dp2 + 1
            t22 = (nums2[i - 1] <= nums2[i] ? dp2 + 1 : 1);
            dp1 = max(t11 , t21);
            dp2 = max(t12 , t22);
            ans = max({ans , dp1 , dp2});
        }
        return ans;
    }
};