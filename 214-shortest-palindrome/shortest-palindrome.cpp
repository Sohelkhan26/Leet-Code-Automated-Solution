class Solution {
public:
    string shortestPalindrome(string s) {
        long long base = 199 , mod = 1e9 + 9 , prefix = 0 , suffix = 0 , power = 1;
        if(s == "")
            return s;
        int n = s.size() , idx;
        for(int i = 0 ; i < n ; i++){
            prefix = (prefix * base + (s[i] - 'a' + 1)) % mod;
            suffix = (suffix + (s[i] - 'a' + 1) * power) % mod; // or just vice versa
            power = (power * base) % mod;
            if(prefix == suffix)
                idx = i;
        }
        string add = s.substr(idx + 1);
        reverse(add.begin() , add.end());
        return add + s;
    }
};

/*
Really Nice problem for RabinKarp algorithm.
Given a string convert it to a palindrome by adding least possible characters in front of it.

Reframing the problem by find the biggest palindromic substring starting at index 0, then we just add the ramaining suffix after reversing to the original string.

So, rolling hash could be used here. Palindrome reads same forward and backward. So, for a string, calculate hash once in a normal way, and another time, as if it was reversed. If the both hash match, we found a palindrome.
*/