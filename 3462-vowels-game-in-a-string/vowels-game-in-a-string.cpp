class Solution {
public:
    bool doesAliceWin(string s) {
        for(char c : s)
            if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
                return true;
        return false;
    }
};