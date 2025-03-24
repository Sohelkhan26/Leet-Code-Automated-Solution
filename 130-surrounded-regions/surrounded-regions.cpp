class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size();
        vector<vector<bool>> vis(n , vector<bool> (m));
        function<void(int,int)> dfs = [&](int i , int j){
            if(vis[i][j])
                return;
            board[i][j] = '*';
            vis[i][j] = true;
            for(auto &[di , dj] : vector <pair<int,int>> {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}}){
                int newI = i + di , newJ = j + dj;
                if(min(newI , newJ) >= 0 and newI < n and newJ < m and board[newI][newJ] == 'O')
                    dfs(newI , newJ);
            }
        };
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(i == 0 or i == n - 1 or j == 0 or j == m - 1)
                    if(board[i][j] == 'O' and not vis[i][j])
                        dfs(i , j);
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                board[i][j] = board[i][j] == '*' ? 'O' : 'X';
    }
};