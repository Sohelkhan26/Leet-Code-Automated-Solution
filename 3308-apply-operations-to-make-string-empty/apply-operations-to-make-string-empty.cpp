class Solution {
public:
    string lastNonEmptyString(string s) {
        int n = s.size() , stay = -1;
        vector<int> count(26) , occur(n);
        for(int i = 0 ; i < n ; i++)
            occur[i] = ++count[s[i] - 'a'];
        stay = *max_element(occur.begin() , occur.end());
        string ans;
        for(int i = 0 ; i < n ; i++)
            if(occur[i] == stay)
                ans.push_back(s[i]);
        return ans;
    }
};