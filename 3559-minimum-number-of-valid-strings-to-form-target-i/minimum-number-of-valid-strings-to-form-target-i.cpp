class Solution {
public:
    struct node{
        node* child[26];
        node(){
            fill(child , child + 26 , nullptr);
        }
    };
    node* root;
    void add(string &s){
        node* curr = root;
        for(char &c : s){
            int i = c - 'a';
            if(curr -> child[i] == nullptr)
                curr -> child[i] = new node();
            curr = curr -> child[i];
        }
    }
    vector <int> dp;
    int solve(int i){
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int ans = 1e5;
        node* curr = root;
        for(int start = i ; start < n ; start++){
            int idx = target[start] - 'a';
            if(curr -> child[idx] == nullptr) // no nodes to match prefix, 
                break;
            ans = min(ans , 1 + solve(start + 1)); // [i..start] is prefix, solve subproblem
            curr = curr -> child[idx];
        }
        return dp[i] = ans;
    }
    int n;
    string target;
    int minValidStrings(vector<string>& words, string s) {
        root = new node();
        n = s.size();
        target = s;
        dp.resize(n , -1);
        for(string &s : words)
            add(s);
        int ans = solve(0);
        return ans == 1e5 ? -1 : ans;
    }
};

/*
concatenate min number of prefix from strings in word array to form target.
So, individual prefix should be as large as possible.
can we be greedy? sort the array? there is no way to ensure the position of prefix in target. 
current prefix can be in the middle of target? then what?
Trie? but how do we ensure min prefix taken?
Trie + DP is needed to solve this problem. Not only trie will solve this.
fix breaking point for prefix in target and solve the subproblem.
if target[0..i] is a prefix of some words[i] , then solve(i + 1)
use trie for efficient prefix check. But don't write a seperate function. do it inside the solve function, or get TLE.
*/