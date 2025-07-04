class Solution {
public:
    const int mod = 1e9 + 7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long sum = 0 , ans = 0;
        set <int> st;
        for(int i = 0 ; i < n ; i++)
            sum = (sum + abs(nums1[i] - nums2[i]))  , st.insert(nums1[i]);
        ans = sum;
        for(int i = 0 ; i < n ; i++){
            sum -= abs(nums1[i] - nums2[i]);
            auto it = st.lower_bound(nums2[i]);
            if(it != st.end())
                ans = min(ans , (sum + abs(*it - nums2[i])) );
            if(it != st.begin())
                ans = min(ans , (sum + abs(*prev(it) - nums2[i])) );
            sum += abs(nums1[i] - nums2[i]);
        }
        return ans % mod;
    }
};

/*
Calculate absolute sum diff for initial array.
For each element greedily replace it with another element and recalculate answer.
Return the min. 
Just a hunch. could be wrong.
choose greedily how? binary search over nums1?
*/