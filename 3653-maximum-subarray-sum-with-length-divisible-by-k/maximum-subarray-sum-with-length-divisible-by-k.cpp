class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector <long long> prev(k + 1 , 1e18);
        prev[0] = 0;
        long long pref = 0 , ans = LLONG_MIN , n = nums.size();
        for(int i = 0 ; i < n ; i++){
            pref += nums[i];
            int len = i + 1 , rem = len % k;
            // if(rem == 0)
            //     ans = max(ans , pref); // this is for the initial round. Once prev[0] is updated , it isn't needed.
            ans = max(ans , pref - prev[rem]);
            prev[rem] = min(prev[rem] , pref); 
        }
        return ans;
    }
};

/*
Same as this: If Same sum repeats , then the sum of in between elements are 0. 
If remainder length repeats , then current subarray is divisible by k.
To maximize the sum , we store minimum sum at each length % k.
*/