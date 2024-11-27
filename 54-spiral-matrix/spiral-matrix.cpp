class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size() , m = matrix[0].size();
        function<void(int,int,bool)> dfs = [&](int i , int j , bool goUp) -> void{
            if(min(i , j) < 0 or i == n or j == m or matrix[i][j] == -111)
                return;
            ans.push_back(matrix[i][j]);
            matrix[i][j] = -111;
            if(goUp)
                dfs(i - 1 , j , true);
            dfs(i , j + 1 , false);
            dfs(i + 1 , j , false);
            dfs(i , j - 1 , false);
            dfs(i - 1 , j , true);
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