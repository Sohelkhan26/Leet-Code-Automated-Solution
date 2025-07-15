class Solution {
public:
    unordered_set <string> vis;
    string ans;
    string op1(string s , int a){
        for(int i = 1 ; i < s.size() ; i += 2)
            s[i] = '0' + (s[i] - '0' + a) % 10;
        return s;
    }
    string op2(string s , int b){
        rotate(s.begin() , s.begin() + b , s.end());
        return s;
    }
    void dfs(string s , int a , int b){
        if(vis.contains(s))
            return;
        ans = min(ans , s);
        vis.insert(s);
        dfs(op1(s , a) , a , b);
        dfs(op2(s , b) , a , b);
    }
    string findLexSmallestString(string s, int a, int b) { 
        ans = string((int)s.size() , '9');
        dfs(s , a , b);
        return ans;
    }
};