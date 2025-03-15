class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        for(int i = n - 2 ; i >= 0 ; i--)
            shifts[i] = (shifts[i + 1] + shifts[i]) % 26;
        for(int i = 0 ; i < s.size() ; i++){
            int a = s[i] - 'a';
            a = (a + shifts[i]) % 26;
            s[i] = a + 'a';
        }
        return s;
    }
};