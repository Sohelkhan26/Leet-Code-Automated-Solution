class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){
            int x1 = bottomLeft[i][0] , y1 = bottomLeft[i][1];
            int x2 = topRight[i][0] , y2 = topRight[i][1];
            for(int j = i + 1 ; j < n ; j++){
                int x3 = bottomLeft[j][0] , y3 = bottomLeft[j][1];
                int x4 = topRight[j][0] , y4 = topRight[j][1];
                int X1 = max(x1 , x3) , Y1 = max(y1 , y3); // bottom-left of inner rectangle
                int X2 = min(x2 , x4) , Y2 = min(y2 , y4); // top-right of inner rectangle
                if(X1 < X2 and Y1 < Y2){
                    int side = min(abs(X1 - X2) , abs(Y1 - Y2)); // take the min cause we need square
                    ans = max(ans , 1ll * side * side);
                }
            }
        }
        return ans;
    }
};
/*
we have to find biggest square residing inside at least 2 or more rectangles.
It's just a complicated way of saying inside 2 rectangles.
since array length is small we will brute force it.
*/