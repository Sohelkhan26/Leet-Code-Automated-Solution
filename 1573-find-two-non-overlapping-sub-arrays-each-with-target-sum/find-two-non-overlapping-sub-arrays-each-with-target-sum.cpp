class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map <int,int> seen;
        int n = arr.size() , prefix = 0 , ans = n + 1 , best = n + 1;
        vector <int> bestTill(n , n + 1);
        seen[0] = -1;
        for(int i = 0 ; i < n ; i++){ 
            prefix += arr[i];
            if(seen.contains(prefix - target)){
                int start = seen[prefix - target]; // [start + 1 .. i] subarray has sum == target, no need for + 1
                if(start != -1) // if start == -1 only one valid subarray found
                    ans = min(ans , i - start + bestTill[start]);
                best = min(best , i - start);
            }
            bestTill[i] = best;
            seen[prefix] = i;
        } 
        return ans == n + 1 ? -1 : ans;
    }
};

/*
Find two non-overlapping subarray with sum = target
Minimize sum of length of subarrays
Prefix Sum Sliding window is for sure.
Couldn't handle the part non-verlapping and Implement it. 
Good problem.
*/