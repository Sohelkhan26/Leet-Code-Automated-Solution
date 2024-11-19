class Solution {
public:
    bool doesAliceWin(string s) {
        return any_of(s.begin() , s.end() , [&](char c){
            return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
        });
    }
};