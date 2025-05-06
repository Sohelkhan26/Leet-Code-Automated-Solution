class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        int ans = 1 , mod = 1e9 + 7 , prevEnd = -1;
        sort(ranges.begin() , ranges.end());
        for(auto &range : ranges){
            if(prevEnd < range[0]) // this range forms a new component.
                ans = (ans * 2) % mod;
            prevEnd = max(prevEnd , range[1]); // sorted by first value only, no guarantee 2nd value is also sorted.
        }
        return ans;
    }
};
/*
Understanding the problem can be quite tricky.
Overlapping ranges are counted as one range(because both of them are to be in the same group).
Think each as components. Overlapping ranges belongs to same component.
For each range you can place it in either group 1 or group 2.
So for each range, number-of-ways = 2

If we find that the ranges form k non-overlapping connected components, and we can choose either group 1 or group 2 for each component, then the number of ways to assign the components to the groups is: 2^\U0001d458

If all ranges overlap and form a single group, you can only assign that group to either group 1 or 2 → answer = 2

If no ranges overlap, each is its own component → answer = 2^\U0001d45b
*/