class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        return (s.find('1') != -1) == (target.find('1') != -1);
    }
};