class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        auto ham = [&](string &a , string &b){
            if(a.size() != b.size())
                return false;
            int diff = 0;
            for(int i = 0 ; i < a.size() ; i++)
                if(a[i] != b[i])
                    diff++;
            return diff == 1;
        };
        int n = words.size() , len = 0 , maxI = 0;
        vector <int> dp(n , 1) , prev(n , -1);
        for(int i = 1 ; i < n ; i++){ // try to include i th word to every subsequence ending before it (i - 1)
            for(int j = 0 ; j < i ; j++){ // subsequence ending at j
                if(ham(words[i] , words[j]) and groups[i] != groups[j] and dp[j] + 1 > dp[i]) // if we include i'th word, it will increase dp[j] by one. 
                    dp[i] = dp[j] + 1 , prev[i] = j;
            }
            if(dp[i] > len)
                len = dp[i] , maxI = i;
        }
        vector <string> ans;
        for(int i = maxI ; i >= 0 ; i = prev[i])
            ans.push_back(words[i]);
        reverse(ans.begin() , ans.end());
        return ans;
    }
};