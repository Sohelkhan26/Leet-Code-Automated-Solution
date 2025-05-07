class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n <= 2)  
            return s;
        string ans = s.substr(0 , n / 2);
        sort(ans.begin() , ans.end());
        string revAns = ans;
        if(n % 2) // insert the middle char. Don't do it before assigning reverse part.
            ans.push_back(s[n / 2]);
        reverse(revAns.begin() , revAns.end());
        return ans + revAns;
    }
};