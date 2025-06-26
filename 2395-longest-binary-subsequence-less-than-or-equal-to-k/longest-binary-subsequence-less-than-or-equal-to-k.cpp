class Solution {
public:
    int k;
    map <pair<int,int> , int> dp;
    int solve(string &sub , int i , string &s){
        if(i == s.size())
            return not sub.empty() and stoi(sub , nullptr , 2) <= k ? 0 : -1e4;
        if(not sub.empty() and stoi(sub , nullptr , 2) > k)
            return -1e4;
        int key = stoi(sub , nullptr , 2);
        if(dp.contains({key , i}))
            return dp[{key , i}];
        int take = 0 , skip = solve(sub , i + 1 , s);
        sub.push_back(s[i]);
        take = 1 + solve(sub , i + 1 , s);
        sub.pop_back();
        return dp[{key , i}] = max(take , skip);
    }
    int longestSubsequence(string s, int K) {
        int ans = s.size() , bit = 0;
        for(int i = s.size() - 1 ; i >= 0 ; i-- , bit++){
            if(s[i] == '1'){
                if(bit >= 31 or (1 << bit) > K)
                    ans--;
                if(bit < 31)
                    K -= (1 << bit);
            }
        }
        return ans;
    }
};


/*
Given a binary string and a positive integer k
return longest subseq (convereted to decimal) is <= k

subseq can contains leading 0(all zero possible? yeah , 1 <= k <= 1e9)
all 0 subseq always possible.
subseq can be only 32 length long. 
*/