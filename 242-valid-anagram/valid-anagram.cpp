class Solution {
public:
    bool isAnagram(string s, string t) {
        auto counter = [&](string s){
            long long ans = 0;
            for(char &c : s)
                ans += pow(3 , c - 'a');
            return ans;
        };
        return counter(s) == counter(t);
    }
};
/*
Same trick used as : 869. Reordered Power of 2 
https://leetcode.com/problems/reordered-power-of-2/description/
*/