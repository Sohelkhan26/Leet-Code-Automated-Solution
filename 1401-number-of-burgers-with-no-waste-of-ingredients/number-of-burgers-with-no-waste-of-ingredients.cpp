class Solution {
public:
    vector<int> numOfBurgers(int t , int c) {
        int low = 0 , high = c , jumbo , ans , totalB = c;
        while(low <= high){
            jumbo = low + (high - low) / 2;
            int small = (c - jumbo); // both burger require 1 cheese. So we should be able to make c - jumbo small burgers. And every small burger needs 2 tomato
            int tSliceNeeded = jumbo * 4 + small * 2; // calculating tomato slice needed.
            if(tSliceNeeded == t)
                return {jumbo , small};
            else if(tSliceNeeded < t) // There is only one answer. Not a monotonic increasing or decreasing problem.
                low = jumbo + 1;
            else high = jumbo - 1;
        }
        return {};
    }
};

/*
Binary search over number of Jumbo burgers that can be made.
*/