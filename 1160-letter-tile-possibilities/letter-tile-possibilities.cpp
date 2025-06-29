class Solution {
public:
    int fact[8] = { 1, 1, 2, 6, 24, 120, 720, 5040 };
    unordered_set <string> seen;
    int calc(string sub){
        int n = sub.size() , count[26] = {};
        for(char &c : sub)
            count[c - 'A']++;
        int ans = fact[n];
        for(int i = 0 ; i < 26 ; i++)
            ans /= fact[count[i]];
        return ans;
    }
    int dfs(int i , string sub , string &s){
        if(i == s.size())
            return seen.insert(sub).second ? calc(sub) : 0;
          
        return dfs(i + 1 , sub , s) + dfs(i + 1 , sub + s[i] , s);
    } 
    int numTilePossibilities(string tiles) {
        sort(tiles.begin() , tiles.end());
        return dfs(0 , "" , tiles) - 1; // -1 for empty subseq
    }
};