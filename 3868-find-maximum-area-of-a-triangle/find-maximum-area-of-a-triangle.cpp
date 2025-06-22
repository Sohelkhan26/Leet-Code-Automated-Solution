class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        unordered_map <int,pair<int,int>> xToY , yToX;
        long long ans = 0;
        int xMax = INT_MIN , xMin = INT_MAX , yMax = INT_MIN , yMin = INT_MAX; 
        for(auto &it : coords){
            int x = it[0] , y = it[1];
            if(not xToY.contains(x))
                xToY[x] = {INT_MAX , INT_MIN};
            xToY[x].first = min(xToY[x].first , y); // stores two points on the same x value that are furthest apart.
            xToY[x].second = max(xToY[x].second , y);
            if(not yToX.contains(y))
                yToX[y] = {INT_MAX , INT_MIN};
            yToX[y].first = min(yToX[y].first , x); // stores two poins on the same y value that are furthest apart
            yToX[y].second = max(yToX[y].second , x);
            xMax = max(x , xMax);
            xMin = min(x , xMin);
            yMax = max(y , yMax);
            yMin = min(y , yMin);
        }
        for(auto &[x , val] : xToY){
            long long base = (val.second - val.first);
            long long height = max(abs(x - xMax) , abs(x - xMin));
            ans = max(ans , base * height);
        }
        for(auto &[y , val] : yToX){
            long long base = (val.second - val.first);
            long long height = max(abs(y - yMax) , abs(y - yMin));
            ans = max(ans , base * height);
        }
        return ans == 0 ? -1 : ans;
    }
};

/*
Mainly implementation problem with a bit of observation.
We need to return 2 * A
There could be many formula to calculate area of an triangle. 2 * A gives us hint of 0.5 * base * height. I couldn't come up with it.
Since, one side needs to be parallel with x/y axis, 
fix two points in the same x/y value. They should act as base.
Pick another point such that height between them is maximized.
If base is parallel to y axis i.e: two points of base has same 'x' value
Then, height = abs(x - (min/max(x) other than base))
*/