class Spreadsheet {
public:
    int n , m = 26;
    vector<vector<int>> grid;
    Spreadsheet(int rows) {
        grid.resize(rows , vector<int> (26));
        n = rows;
    }
    
    pair<int,int> cord(string s){
        return {stoi(s.substr(1)) - 1 , s[0] - 'A'};
    }
    void setCell(string cell, int value) {
        auto [x , y] = cord(cell);
        grid[x][y] = value;
    }
    
    void resetCell(string cell) {
        auto [x , y] = cord(cell);
        grid[x][y] = 0;
    }
    
    int getValue(string formula) {
        int plus = formula.find('+');
        string a = formula.substr(1 , plus - 1) , b = formula.substr(plus + 1);
        auto getVal = [&](string a){
            auto [x1 , y1] =  cord(a);
            return grid[x1][y1];
        };
        cout << a << ' ' << b << endl;
        int x = (isdigit(a[0]) ? stoi(a) : getVal(a));
        int y = (isdigit(b[0]) ? stoi(b) : getVal(b));
        return x + y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */