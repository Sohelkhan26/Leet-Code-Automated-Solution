class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        set <int> s;

        for(int len = 1 ; len <= min(n , m) ; len += 2){
            int d = len / 2;
            for(int i = 0 ; i + len <= n ; i++){
                for(int j = 0 ; j + len <= m ; j++){
                    if(d == 0) // single cell rhombus
                        s.insert(grid[i][j]);
                    else{
                        // top corner
                        int x = i , y = j + d;
                        int sum = 0;
                        for(int k = 0 ; k < d ; k++)
                            sum += grid[x++][y++]; // border -> '\' downward
                        for(int k = 0 ; k < d ; k++)
                            sum += grid[x++][y--]; // border -> '/'
                        for(int k = 0 ; k < d ; k++)
                            sum += grid[x--][y--]; // border -> '\' upward
                        for(int k = 0 ; k < d ; k++)
                            sum += grid[x--][y++]; // border -> '/'
                        s.insert(sum);
                    }
                }
            }
        }
        return vector<int> (s.rbegin() , (s.size() > 3 ? next(s.rbegin() , 3) : s.rend()));
    }
};

/*
Two rhombus are different if at least one corner is different.
Greedily pick three largest number? see if they can be included in 3 rhombus?
len iterates every possible length of the "wrapping square" of a rhombus. i and j are the row and column of the top-left of the "wrapping square". So, (i , j + d) is the top corner of the rhombus.
In the innermost loop, we iterate for edges of the rhombus, top->right->bottom->left->top.
*/