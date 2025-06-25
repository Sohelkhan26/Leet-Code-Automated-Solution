class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low = -1e10 ,  high = 1e10 , mid , ans = -1;
        int n = nums1.size() , m = nums2.size();
        auto countProductLessThanK = [&](long long product){
            long long count = 0;
            for(int &x : nums1){
                int low = 0 , high = m - 1 , mid , ans = -1;
                while(low <= high){
                    mid = low + (high - low) / 2;
                    if((x >= 0 and 1ll * x * nums2[mid] <= product) or (x < 0 and 1ll * x * nums2[mid] > product))
                        ans = mid , low = mid + 1;
                    else 
                        high = mid - 1;
                }
                count += (x >= 0 ? ans + 1 : m - ans - 1);
            }
            return count;
        };
        while(low <= high){
            mid = low + (high - low) / 2;
            if(countProductLessThanK(mid) >= k)
                ans = mid , high = mid - 1;
            else low = mid + 1;
        }
        return ans;
    }
};