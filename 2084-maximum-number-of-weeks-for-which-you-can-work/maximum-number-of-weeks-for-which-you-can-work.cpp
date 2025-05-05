class Solution {
public:
    #define all(a) a.begin() , a.end()
    long long numberOfWeeks(vector<int>& nums) {
        long long total = accumulate(all(nums) , 0ll) , mx = *max_element(all(nums)) , 
        rest = total - mx;
        if(mx > rest)
            return 2 * rest + 1;
        return total;
    }
};

/*
Requires huge level of observation and intuition. 
Observation is: no matter what the parity and numbers are, unless one milestone is greater than all other milestones combined, then all the milestones can be completed.
If maxElement is greater, then all lower milestones can be completed by interleaving maxElement in between. And 1 from maxElement again at the end.
*/