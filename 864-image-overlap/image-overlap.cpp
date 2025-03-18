class Solution {
public:
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size() , ans = 0 , overlap = 0;
        for(int xOffset = - n + 1 ; xOffset < n ; xOffset++){
            for(int yOffset = - n + 1 ; yOffset < n ; yOffset++){
                overlap = 0;
                for(int i = 0 ; i < n ; i++){
                    for(int j = 0 ; j < n ; j++){
                        int newI = i + xOffset , newJ = j + yOffset;
                        if(min(newI , newJ) >= 0 and newI < n and newJ < n)
                            overlap += (a[i][j] == b[newI][newJ] and a[i][j]);
                    }
                    ans = max(ans , overlap);
                }
            }
        }
        return ans;
    }
};