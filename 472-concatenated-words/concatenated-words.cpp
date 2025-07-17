class Solution {
public: 
    struct Node{
        Node* child[26] = {};
        bool isEnd = false;
    } *root = new Node();
    void add(string &s){
        Node* curr = root;
        for(char &c : s){
            if(curr -> child[c - 'a'] == nullptr)
                curr -> child[c - 'a'] = new Node();
            curr = curr -> child[c - 'a'];
        }
        curr -> isEnd = true;
    }
    vector <bool> dp;
    void solve(int start , string &s , Node* curr){
        for(int i = start ; i < s.size() ; i++){
            int idx = s[i] - 'a';
            if(curr -> child[idx] == nullptr)
                return;
            curr = curr -> child[idx]; // after this curr points to first node
            if(curr -> isEnd) // smaller word until 'i' has been found
                dp[i + 1] = true;
        }
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin() , words.end() , [&](string &a , string &b){
            return a.size() < b.size();
        }); // start with smaller words
        vector <string> ans;
        for(string &s : words){
            int n = s.size();
            Node* curr = root;
            dp = vector<bool> (n + 1);
            dp[0] = true;
            for(int i = 0 ; i < n ; i++){
                if(not dp[i])continue;
                solve(i , s , curr); 
                if(dp[n]){
                    ans.push_back(s);
                    break;
                }
            }
            add(s); // add later such that own word don't mess up the checking for smaller words
        }
        return ans;
    }
};

/*
DP with Trie. But Such a hassle took too much time. For silly mistakes.
Trie + DFS gives TLE. In DFS use local curr pointer to traverse Trie. Used global variable so didn't reset properly for every DFS call, couldn't find it, used too much time.
When searching for a Trie, for the first time:
curr -> child[c - 'a'] is the first node, not curr
*/