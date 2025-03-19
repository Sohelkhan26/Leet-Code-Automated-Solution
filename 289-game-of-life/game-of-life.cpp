class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int one = 0;
                for(int dx = -1; dx <= 1; dx++) {
                    for(int dy = -1; dy <= 1; dy++) {
                        if(dx == 0 && dy == 0) continue;  // Skip the current cell
                        int newI = i + dx, newJ = j + dy;
                        if(newI >= 0 && newJ >= 0 && newI < n && newJ < m)
                            one += board[newI][newJ];
                    }
                }
                
                if(board[i][j] == 1) 
                    ans[i][j] = (one == 2 or one == 3) ? 1 : 0;
                else
                    ans[i][j] = (one == 3) ? 1 : 0;
            }
        }
        board = ans;
    }
};

/*
Do as said in the problem. 
Live cell lives on, if there are 2 | 3 live neighbours. Otherwise it dies.
Dead cell relives if there is exactly 3 live neighbours.
*/
