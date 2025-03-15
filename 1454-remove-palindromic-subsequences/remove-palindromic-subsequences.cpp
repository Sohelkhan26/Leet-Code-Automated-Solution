class Solution {
public:
    int removePalindromeSub(string s) {
        for(int i = 0 , j = s.size() - 1 ; i < j ; i++ , j--)
            if(s[i] != s[j])
                return 2;
        return 1;
    }
};

/*
Not bad for a easy problem.
Read problem description carefully.
Allowed to remove palindromic subsequence. And string consits of only 'a' and 'b'.
If the string is already palindrome, we can remove it whole.
Otherwise, 2 subsequence is required to remove. One with all 'a', other with all 'b'. 
*/