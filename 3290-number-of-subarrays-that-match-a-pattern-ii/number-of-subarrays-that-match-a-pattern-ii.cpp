class Solution {
public:
    int robinKarp(vector <int> &a , vector <int> &b){
        int n = a.size() , m = b.size() , ans = 0 , mod = 1e9 + 9;
        long long base = 109 , maxPower = 1 , hashA = 0 , hashB = 0;
        for(int &i : b){
            hashB = (hashB * base + (i + 1)) % mod;
            maxPower = (maxPower * base) % mod;
        }
        for(int right = 0 ; right < a.size() ; right++){
            hashA = (hashA * base + (a[right] + 1)) % mod; // calc hash in source to compare
            // if((right + 1) > m) // shrink window to keep same size as pattern
            //     hashA = (hashA - (maxPower * (a[right - m] + 1)) % mod ) % mod;
            if((right + 1) > m)
                hashA = (mod + hashA - (maxPower * (a[right - m] + 1)) % mod) % mod;
            if(hashA < 0)
                hashA += mod;
            if(right + 1 >= m and hashA == hashB)
                ans++;
        }
        return ans;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        vector <int> diff;
        for(int i = 1 ; i < n ; i++)
            diff.push_back((nums[i] > nums[i - 1] ? 1 : nums[i] < nums[i - 1] ? -1 : 0));
        return robinKarp(diff , pattern);
    }
};