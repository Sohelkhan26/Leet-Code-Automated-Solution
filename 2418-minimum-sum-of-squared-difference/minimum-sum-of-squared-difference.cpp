class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long ans = 0 , n = nums1.size() , K = k1 + k2 , extra = 0;
        for(int i = 0 ; i < n ; i++)
            nums1[i] = abs(nums1[i] - nums2[i]);
        int low = 0 , high = 1e5 , mid , maxDiff = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            long long op = 0;
            for(int &num : nums1)
                op += max(0 , num - mid);
            if(op <= K){
                maxDiff = mid;
                extra = K - op;
                high = mid - 1;
            }else low = mid + 1;
        }
        for(int &num : nums1){
            long long val = 0;
            if(num < maxDiff)
                val = num;
            else val = max(0 , maxDiff - (--extra >= 0));
            ans += val * val;
        }
        return ans;
    }
};