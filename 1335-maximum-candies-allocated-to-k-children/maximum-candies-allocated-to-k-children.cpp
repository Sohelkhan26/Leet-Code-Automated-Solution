class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1 , high = 1e7 , mid , ans = 0;
        auto allocate = [&](int candy) -> bool{
            long long child = k;
            for(int i : candies)
                child -= (int)(i / candy);
            return child <= 0;
        };
        while(low <= high){
            mid = low + (high - low) / 2;
            if(allocate(mid)){
                ans = mid;
                low = mid + 1;
            }else high = mid - 1;
        }
        return ans;
    }
};