class Solution {
public:
    string smallestPalindrome(string s) {
        map <char,int> freq;
        for(int i = 0 ; i < s.size() / 2 ; i++)
            freq[s[i]]++;
        int filled = 0;
        for(auto &[c , f] : freq){
            fill(s.begin() + filled , s.begin() + filled + f , c); // fill from left
            fill(s.rbegin() + filled , s.rbegin() + filled + f , c); // fill from right
            filled += f;
        }
        return s;
    }
};

/*
If you are wondering what happens to odd length palindrome, The middle character gets filled twice by the came character. So, don't sweat.
*/