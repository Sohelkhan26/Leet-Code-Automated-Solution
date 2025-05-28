class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin() , hBars.end());
        sort(vBars.begin() , vBars.end());
        auto count = [&](vector<int> &a){
            int cnt = 2 , ans = 2;
            for(int i = 1 ; i < a.size() ; i++){
                if(a[i] == (a[i - 1] + 1))
                    cnt++;
                else cnt = 2;
                ans = max(ans , cnt);
            }
            return max(ans , cnt);
        };
        int h = count(hBars) , v = count(vBars) , side = min(h , v);
        return side * side;
    }
};

/*
n and m are irrelevent. If we can't remove them no need to fret over them.
Removing first bar gives us two (1 X 1) square , after that removing one bar gives us 1 square. Removing consecutive bars allows us to make our potential square bigger and bigger.
Now for one bar removed from horizontal, removing vertical bar at any position allows us to make a square.
So minimum of these two is the side of our max Square.
*/