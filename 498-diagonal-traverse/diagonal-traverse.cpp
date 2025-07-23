class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size() , row = 0 , col = 0;
        vector<int> ans(n * m);
        for(int pos = 0 ; pos < m * n ; pos++){
            ans[pos] = mat[row][col];
            if((row + col) % 2 == 0){ // (row + col) == constant for  left-right upward diagonals. Based on it's parity we have to decide if we should go up or down.
                if(col == m - 1) // col reaches end of mat[i]
                    row++; // start from new diagonal starting under it
                else if(row == 0) // end of diagonal, start from next diagonal at col + 1 , go down
                    col++;
                else // diagonal not finished yet keep going
                    col++ , row--;
            }else{ // go down diagonally
                if(row == n - 1)
                    col++;
                else if(col == 0)
                    row++;
                else
                    row++ , col--;
            }
        }
        return ans;
    }
};