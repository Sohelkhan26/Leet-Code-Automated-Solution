class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double table[101][101] = {0.0};
        table[0][0] = poured;
        for(int row = 0 ; row < 100 ; row++){
            for(int glass = 0 ; glass <= row ; glass++){
                if(table[row][glass] >= 1){
                    table[row + 1][glass] += (table[row][glass] - 1) / 2.0;
                    table[row + 1][glass + 1] += (table[row][glass] - 1) / 2.0;
                    table[row][glass] = 1.0;
                }
            }   
        }
        return table[query_row][query_glass];
    }
};

/*
Every row has row glasses (1 indexed) or row + 1 glasses (0 indexed).
If a glass in some row has more than it's capacity, it passes it to adjacent glass in the next row. Simulate the process.
*/