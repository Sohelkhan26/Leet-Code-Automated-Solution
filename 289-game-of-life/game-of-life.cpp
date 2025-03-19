class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int one = 0;
                for(int dx = -1; dx <= 1; dx++) {
                    for(int dy = -1; dy <= 1; dy++) {
                        if(dx == 0 && dy == 0) continue;  // Skip the current cell
                        int newI = i + dx, newJ = j + dy;
                        if(newI >= 0 && newJ >= 0 && newI < n && newJ < m)
                            one += (board[newI][newJ] & 1);
                    }
                }
                
                if(board[i][j] == 1) 
                    board[i][j] |= (one == 2 or one == 3) ? 2 : 0; // using 2 sets the second bit
                else
                    board[i][j] |= (one == 3) ? 2 : 0;
            }
        }
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                board[i][j] >>= 1;
    }
};

/*
Do as said in the problem. 
Live cell lives on, if there are 2 | 3 live neighbours. Otherwise it dies.
Dead cell relives if there is exactly 3 live neighbours.
Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
To update the board inplace, use the 2nd bit store the updated state of each cell. After the whole operation, simply shift every cell 1 bit to the right.
*/
