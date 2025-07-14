class Solution {
public:
    typedef unsigned long long ull;
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        ull total = accumulate(nums.begin() , nums.end() , 1ll , [&](ull prod , int i){
            return prod * 1ll * i;
        }); 
        int n = nums.size() , limit = (1 << n);
        for(int i = 0 ; i < limit ; i++){
            ull sub = 1;
            for(int j = 0 ; j < n ; j++){
                int mask = (1 << j);
                if(i & mask)
                    sub *= nums[j];
            }
            if(sub == target and 1ull * sub * target == total)
                return true;
        }
        return false;
    }
};