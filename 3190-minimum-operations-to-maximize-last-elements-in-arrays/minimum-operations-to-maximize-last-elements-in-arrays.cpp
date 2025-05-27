class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        auto solve = [&](vector<int> &a , vector<int> &b){
            int swap = 0;
            for(int i = 0 ; i < n - 1 ; i++){
                if(a[i] <= a[n - 1] and b[i] <= b[n - 1]) // good without swapping
                    continue;
                else if(a[i] <= b[n - 1] and b[i] <= a[n - 1]) // swapping solves the problem
                    swap++;
                else // even swapping won't help
                    return n + 1; // serves as can't infinite swap
            }
            return swap;
        };
        int ans = solve(nums1 , nums2);
        swap(nums1[n - 1] , nums2[n - 1]);
        ans = min(ans , 1 + solve(nums1 , nums2));
        return ans == n + 1 ? -1 : ans;
    }
};

/*
DP is overkill for this problem. Implementation should be quite hard too.
This is one of the problems where you need to think step by step , take algorithmic approach.
One main thing is we can't transfer any other element to n - 1th position.
They may swap themselves, but not other than nums1[n - 1] or nums2[n - 1].
So, For n - 1 index we have two options , swap or dont.
And for each option in n - 1 we have 2 options for every other index swap or dont.
If we swap n - 1 position, then every element, nums1[i] should be <= nums1[n - 1] and nums2[i] <= nums2[n - 1]. Or we can swap them to hold the previous condition. Even after swapping the previous condition don't hold, return -1.
Do this after swapping n - 1 position.
*/