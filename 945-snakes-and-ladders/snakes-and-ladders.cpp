class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size() , start = 1; // val start from 1 , end at n * n
        vector<pair<int,int>> coord(n * n + 1);
        vector<int> colIdx(n);
        iota(colIdx.begin() , colIdx.end() , 0);
        for(int r = n - 1 ; r >= 0 ; r--){ // from last row move upward
            for(int &c : colIdx) // at starting row , col index is [0..n - 1]
                coord[start++] = {r , c};
            reverse(colIdx.begin() , colIdx.end()); // but each row, it gets reversed
        }
        queue <pair<int,int>> q;
        q.push({1 , 0});
        unordered_set <int> vis = {1};
        while(not q.empty()){
            int len = q.size();
            while(len--){
                auto [from , d] = q.front(); q.pop();
                if(from == n * n)
                    return d;
                for(int next = from + 1 ; next <= min(n * n , from + 6) ; next++){
                    auto [x , y] = coord[next];
                    int to = board[x][y] != -1 ? board[x][y] : next;
                    if(not vis.contains(to)){
                        q.push({to , d + 1});
                        vis.insert(to);
                    }
                }
            }
        }
        return -1;
    }
};

/*
move in range [1..6]
if board[i][c] that's a ladder.
if ladder go to board[r][c]. If there is another ladder there don't go.
direction change every row. init = left -> right
start [n - 1 , 0]
return min dice roll to reach [0 , n - 1]
*/