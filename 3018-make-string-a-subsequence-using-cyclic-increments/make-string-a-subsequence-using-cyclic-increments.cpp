class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int left = 0 , right = 0 , n = str1.size() , m = str2.size();
        for(left = 0 ; left < n ; left++){
            int c = str1[left] - 'a' , d = str2[right] - 'a';
            if(c == d or (c + 1) % 26 == d)
                right++;
        }
        return right == m;
    }
};
/*
Input:
Given two strings.
Select a set of indices and replace characters in those indices with the next character in cyclic manner(only once). (basically Saying we can change a character at any index and we can select any number of index)
Return true if it's possibile to turn str2 a subsequence of str1

First approach that came to my mind was dp. For each index we either keep it as it is or replace with next char and check for subsequent indices.
But it would have worked like the two pointer method.

N.B: Make adjumstment to the code so that it account for the fact (replace character in cyclic manner)
*/