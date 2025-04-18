class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        auto valid = [&](string s){
            int n = s.size() , m = pattern.size() , i = 0 , j = 0;
            for(int i = 0 ; i < n ; i++){
                if(isupper(s[i])){
                    if(s[i] != pattern[j])
                        return false;
                }
                j += (s[i] == pattern[j]);
            }
            return j >= m;
        };
        vector <bool> ans;
        for(string &s : queries)    
            ans.push_back(valid(s));
        return ans;
    }
};

/*
Straightforward do as the problem description says.
Every Uppercase char in queries[i] should be present in the "pattern".
And every character of "pattern" should be present in queries[i].
*/