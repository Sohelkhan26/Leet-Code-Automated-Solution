class Solution {
public:
    vector<string> letterCasePermutation(string s) {
       vector<string> ans;
       function<void(int)> solve = [&](int i) -> void{
            if(i == s.size()){
                ans.push_back(s);
                return;
            }
            if(s[i] >= 'a' and s[i] <= 'z'){
                s[i] = toupper(s[i]);
                solve(i + 1);
                s[i] = tolower(s[i]);
            }
            if(s[i] >= 'A' and s[i] <= 'Z'){
                s[i] = tolower(s[i]);
                solve(i + 1);
                s[i] = toupper(s[i]);
            }
            solve(i + 1);
       };
       solve(0);
       return ans;
    }
};