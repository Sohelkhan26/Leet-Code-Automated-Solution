class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n , vector<int> (n));
        int number = 1;
        function<void(int,int,bool)> dfs = [&](int i , int j , bool goUp) -> void{
            if(min(i , j) < 0 or i >= n or j >= n or ans[i][j] != 0)
                return;
            ans[i][j] = number++;
            if(goUp)
                dfs(i - 1 , j , goUp);
            dfs(i , j + 1 , false); // right
            dfs(i + 1 , j , false); // down
            dfs(i , j - 1 , false); // left
            dfs(i - 1 , j , true); // up
        };
        dfs(0 , 0 , false);
        return ans;
    }
};

/*
DFS call sequence এর কারনে ম্যাট্রিক্সের একদম ডান , নিচে , বামে না যাওয়া পর্যন্ত রিটার্ন করবে না। কিন্তু উপরে যাওয়ার জন্য একবার DFS call করলে নেক্সট ডিএফএস কলে গিয়ে আবার ডানে যাওয়া শুরু করবে। যাতে একদম উপর পর্যন্ত যায় সেটা ensure করার জন্য extra if condition apply করতে হইছে। 
1 -> 2 -> 3 -> 4
               5
11   12   13   6 next DFS call এ আবার ডানে যাওয়া শুরু করবে এরকম ভাবে। 
10   9    8    7               
*/