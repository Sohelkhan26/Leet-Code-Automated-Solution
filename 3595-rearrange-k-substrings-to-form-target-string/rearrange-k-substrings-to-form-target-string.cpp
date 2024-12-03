class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size() / k;
        unordered_map <string , int> sub;
        for(int i = 0 ; i < s.size() ; i += n)
            sub[s.substr(i , n)]++;
        for(int i = 0 ; i < t.size() ; i += n)  
            sub[t.substr(i , n)]--;
        for(auto &[key , value] : sub)
            if(value != 0)
                return false;
        return true;
    }
};