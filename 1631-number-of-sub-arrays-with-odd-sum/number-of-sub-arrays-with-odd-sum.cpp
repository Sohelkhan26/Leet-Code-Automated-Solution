class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int seen[2] = {} , ans = 0 , mod = 1e9 + 7 , prefix = 0;
        for(int &x : arr){
            prefix += x;
            int rem = prefix % 2;
            if(rem) // the whole subarray is valid
                ans++;
            ans = (ans + seen[1 - rem]) % mod; // x parity subarray will create valid subarray with (not x) parity
            seen[rem]++;
        }
        return ans;
    }
};

/*
subarray with odd sum -> valid
count valid subarray % mod

Obviously a prefix sum sliding window. Maybe I tried this problem before, timer counter was 35 minutes.
Every prefix sum with odd parity will create a valid subarray, with every previous prefix with even parity. And vice versa.
Only parity of prefix sum is required.
*/