class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size() , ans = 0;
        sort(points.begin() , points.end() , [&](auto a , auto b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        }); // sort by 'x' ascending , 'y' descending when tie.
        for(int alice = 0 ; alice < n ; alice++){
            int maxY = INT_MIN;
            for(int bob = alice + 1 ; bob < n ; bob++){
                int x1 = points[alice][0] , y1 = points[alice][1];
                int x2 = points[bob][0] , y2 = points[bob][1];
                if(y1 >= y2 and maxY < y2)
                    ans++ , maxY = y2;
            }
        }
        return ans;
    }
};

/*
n square should pass. Fix alice and bob. Check in-between points -> this should be optimized. But how? Sorting by 'x' ascending. This ensures
*/