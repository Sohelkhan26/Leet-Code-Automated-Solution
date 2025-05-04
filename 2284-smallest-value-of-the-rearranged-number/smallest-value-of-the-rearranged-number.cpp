class Solution {
public:
    long long smallestNumber(long long num) {
        if(not num)return 0;
        string s = to_string(abs(num));
        sort(s.begin() , s.end() , [&](char a , char b){
            return num > 0 ? a < b : a > b;
        });
        swap(s[0] , s[s.find_first_not_of('0')]);
        return stoll(s) * (num < 0 ? -1 : 1);
    }
};