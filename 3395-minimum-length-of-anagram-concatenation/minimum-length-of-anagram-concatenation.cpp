class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        auto ok = [&](int len){
            vector <int> a(26);
            for(int i = 0 ; i < len ; i++)
                a[s[i] - 'a']++;
            for(int i = len ; i < n ; i += len){
                vector <int> b(26);
                for(int j = i ; j < i + len ; j++){
                    b[s[j] - 'a']++;
                }
                for(int i = 0 ; i < 26 ; i++)
                    if(a[i] != b[i])
                        return false;
            }
            return true;
        };
        for(int i = 1 ; i <= n ; i++)
            if(n % i == 0 and ok(i))
                return i;
        return n;
    }
};
/*
seems like a math problem. count each char freq.
every freq should be divisible by smallest freq. so take gcd of char freq and return.
forgot about most important detail, concatenation. s = "aabb" ans = 4 not 2 
if s was rearrangeable after concatenation then gcd solution would have been correct.

*/