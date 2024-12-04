class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int ans = 0 , n = intervals.size() , prev = intervals[0][1];
        for(int i = 1 ; i < n ; i++)
            if(prev > intervals[i][0]) // Conflicting interval. But which one should we remove?
                ans++ , prev = min(prev , intervals[i][1]); // min ensures that we are discarding the interval that ends later.
            else prev = intervals[i][1];
        return ans;
    }
};
/*
We try to be greedy. If the ending point of an interval exceeds the starting point of next interval then we have to remove one interval. 
But which one should we remove?
Try to be greedy. We should remove the interval that ends later. So that the change of another interval conflicting with it is minimum.
*/