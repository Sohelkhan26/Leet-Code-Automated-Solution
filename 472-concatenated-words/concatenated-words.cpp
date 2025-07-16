class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set <string> wordSet(words.begin() , words.end());
        
        vector<string> ans;
    
        for (string &word : words) {
            int n = word.size();
            vector<bool> dp(n + 1, 0);
            dp[0] = true;
            for(int i = 0 ; i < n ; i++){
                if(not dp[i])continue;
                for(int len = i + 1 ; len <= n ; len++){
                    if(len - i < n and wordSet.count(word.substr(i , len - i)))
                        dp[len] = true;
                }
                if(dp[n]){
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};