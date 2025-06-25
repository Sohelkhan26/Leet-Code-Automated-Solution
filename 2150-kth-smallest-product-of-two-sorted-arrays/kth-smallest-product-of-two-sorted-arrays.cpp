class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low = -1e10 , high = 1e10 , mid , ans = -1;
        int n = nums1.size() , m = nums2.size();

        auto productLessThanK = [&](long long product) -> long long{
            long long count = 0;
            for(int &x : nums1){
                int low = 0 , high = m - 1 , mid , idx = -1;
                while(low <= high){
                    mid = low + (high - low) / 2;
                    if( (x >= 0 and 1ll * nums2[mid] * x <= product) or (x < 0 and 1ll * nums2[mid] * x > product) )
                        idx = mid , low = mid + 1;
                    else 
                        high = mid - 1;
                }
                count += (x >= 0 ? idx + 1 : m - idx - 1);
            }
            return count;
        };

        while(low <= high){
            mid = low + (high - low) / 2; 
            if(productLessThanK(mid) >= k)
                ans = mid , high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }
};

/*


Binary search over the answer space. For a product mid
we will try to count how many product is <= midProduct
If there are >= k many smaller products, that means this could be our k smallest product and as we want exactly k'th smallest product, make high = mid - 1;

But how to count-product-less-than Some product?

both array sorted.
If x1: nums1 is positive,
x1 * nums2 -> increasing order
if x1 is negative
x1 * nums2 -> decreasing order

*/