class Solution {
public: 
    set <int> ans;
    void solve(int i , int n , int k , int num){
        if(i == n){
            if(floor(log10(num)) + 1 == n)
                ans.insert(num);
            return;
        }
        int d = num % 10;
        num *= 10;
        if(d + k < 10)
            solve(i + 1 , n , k , num + (d + k));
        if(d - k >= 0)
            solve(i + 1 , n , k , num + (d - k));
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 0 ; i < 10 ; i++)
            solve(1 , n , k , i);
        vector <int> res;
        for(auto it = ans.begin() ; it != ans.end() ; it++)
            res.push_back(*it);
        return res;
    }
};