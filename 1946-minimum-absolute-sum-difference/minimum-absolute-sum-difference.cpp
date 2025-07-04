class Solution {
public:
    const int mod = 1e9 + 7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long total = 0 , reduce = 0;
        set <int> st(nums1.begin() , nums1.end());
        for(int i = 0 ; i < n ; i++){
            long long currDiff = abs(nums1[i] - nums2[i]);
            total += currDiff;
            auto it = st.lower_bound(nums2[i]);
            if(it != st.end())
                reduce = max(reduce , currDiff - abs(*it - nums2[i]));
            if(it != st.begin())
                reduce = max(reduce , currDiff - abs(*prev(it) - nums2[i]));
        }
        return (total - reduce) % mod;
    }
};

/*
Calculate absolute sum diff for initial array.
For each element greedily replace it with another element and recalculate answer.
Return the min. 
Just a hunch. could be wrong.
choose greedily how? binary search over nums1?
Works just fine. Awesome. 
We want to reduce the absolute sum difference. So, nums1[i] and nums2[i] should be as close as possible to make difference closer to 0
So, lower_bound(nums2[i]) works. Since we can do 1 operation, track the maximum reduce
*/