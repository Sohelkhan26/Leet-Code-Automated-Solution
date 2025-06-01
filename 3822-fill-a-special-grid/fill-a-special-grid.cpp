class Solution {
public:
    int val = 0;
    vector<vector<int>> ans;
    void solve(int rowLow , int rowHigh , int colLow , int colHigh){
        if(rowLow == rowHigh - 1){
            ans[rowLow][colLow] = val++;
            return;
        }
        int rowMid = (rowLow + rowHigh) / 2 , colMid = (colLow + colHigh) / 2;
        solve(rowLow , rowMid , colMid , colHigh); // top-right
        solve(rowMid , rowHigh , colMid , colHigh); // bottom-right
        solve(rowMid , rowHigh , colLow , colMid); // bottom-left
        solve(rowLow , rowMid , colLow , colMid); // top-left
    }
    vector<vector<int>> specialGrid(int n) {
        n = (1 << n);
        ans.resize(n , vector<int> (n));
        solve(0 , n , 0 , n);
        return ans;
    }
};

/*
Clearly seems like a recursive solution.
solve(rL , rH , cL , cH) means fill row [rL , rH) , [cL , cH).
Do this until we have to fill one cell only. note that end value is non-includive. Cause of the 0 based indexing. So when-ever rL == rH - 1 , it means , we have to fill 1 cell.
             cMid |
  rL\cH ------------------- cH
        |                 |
        |                 |
  rMid  |                 |
        |                 |
        |                 |
        |                 |
     rH ------------------- 
*/