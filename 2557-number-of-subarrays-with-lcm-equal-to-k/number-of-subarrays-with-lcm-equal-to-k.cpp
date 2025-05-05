class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map <int,int> prev; // prev[d] is number of subarrays with lcm = d
        for(int &n : nums){
            unordered_map <int,int> curr; // if curr index is i, prev contains subarrays ending at i - 1
            if(k % n == 0){ // if n > k or k % n != 0 then lcm > k
                curr[n]++; // start new subarray from curr index.
                for(auto &[prevN , prevCnt] : prev){ // extend all previous subarrays if possible. i.e: include current element.
                    int LCM = lcm(prevN , n);
                    if(k % LCM == 0) // only extend subarrays that might lead to lcm = k now or in the future.
                        curr[LCM] += prevCnt;
                }
                ans += curr[k];
            }
            swap(curr , prev);
        }
        return ans;
    }
};

/*
Excellent problem.
*/