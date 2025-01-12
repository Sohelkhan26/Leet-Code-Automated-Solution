class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k)
            return false;
        vector <int> count(26);
        for(char c : s)
            count[c - 'a']++;
        for(int i = 0 ; i < 26 ; i++)
            if(count[i] % 2 == 1)
                k--;
        return k < 0 ? false : true;
    }
};