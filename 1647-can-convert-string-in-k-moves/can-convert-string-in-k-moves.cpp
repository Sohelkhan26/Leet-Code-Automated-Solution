class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size() != t.size())
            return false;
        vector <int> count(26);
        for(int i = 0 ; i < s.size() ; i++){
            int diff = (t[i] - s[i]);
            if(diff < 0) // s = d , t = a , d -> e -> f... z -> a 
                diff += 26;
            if(diff > 0 and diff + count[diff] * 26 > k)
                return false;
            count[diff]++;
        }
        return true;
    }
};

/*
s and t len could differ.
For move in range [1..k],
1. shift char in s up
2. do nothing
same character can't be shifted by same diff multiple times.
Therefore, if our strings are "aaa" and "bbb", we need to shift the first letter by 1, the second by 27 (1 + 26), and the third - by 53 (1 + 2 * 26). So, you can accomplish the task if k is equal or greater than 53.
So, we are only interested in difference in s[i] , t[i].
*/