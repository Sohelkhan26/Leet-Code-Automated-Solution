class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if(a > b)
            return numMovesStones(b , a , c);
        if(b > c)
            return numMovesStones(a , c , b);
        int mn = -1;
        if(a == b - 1 and b == c - 1)
            mn = 0;
        else if(b - a > 2 and c - b > 2)
            mn = 2;
        else mn = 1;
        return {mn , (c - b - 1) + (b - a - 1)};
    }
};
/*
Min move is 0/1/2
If all the stones are consecuitve move = 0
If there is at least two conesutive stone move = 1
Other cases, move = 2
For maximum move, each stone should be placed one step before only.
*/