/*
Maintain a window of size p. If the substring present in the window is an anagram push the starting position of the window. If the window exceeds the length of p string shrink the window.
*/
class Solution {
public:
    bool check(vector<int>& s , vector<int> &p){
        for(int i = 0 ; i < s.size() ; i++)
            if(s[i] != p[i])
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> sCount(26) , pCount(26) , ans;
        for(char c : p)
            pCount[c - 'a']++;
        int n = p.size();
        for(int left = 0 , right = 0 ; right < s.size() ; right++){
            sCount[s[right] - 'a']++;
            if(right - left + 1 > n)
                sCount[s[left++] - 'a']--;
            if(check(sCount , pCount))
                ans.push_back(left);
        }
        return ans;
    }
};