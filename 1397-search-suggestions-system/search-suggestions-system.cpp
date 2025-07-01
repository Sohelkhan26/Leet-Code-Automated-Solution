/*
Trie + DFS
insert all products in Trie
for a given prefix, traverse the Trie for that prefix
Now find lexicographically smallest words starting with that prefix using DFS
*/
class Solution {
public:
    struct Node{
        Node* child[26] = {};
        bool isEnd = false;
    } *root , *curr;
    void add(string &s){
        curr = root;
        for(char &c : s){
            if(curr -> child[c - 'a'] == nullptr)
                curr -> child[c - 'a'] = new Node();
            curr = curr -> child[c - 'a'];
        }
        curr -> isEnd = true;
    }
    void dfs(Node* curr , vector<string> &ans , string &word){
        if(ans.size() == 3)
            return;

        if(curr -> isEnd) 
            ans.push_back(word); // don't return yet

        for(char c = 'a' ; c <= 'z' ; c++){ // find lexicographically smallest complete words first
            if(curr -> child[c - 'a'] == nullptr)
                continue;
            word.push_back(c);
            dfs(curr -> child[c - 'a'] , ans , word);
            word.pop_back();
        }
    }
    vector <string> findSuggestion(string &prefix){
        curr = root;
        vector <string> ans;
        for(char &c : prefix){
            if(curr -> child[c - 'a'] == nullptr)
                return ans; // no words with prefix
            curr = curr -> child[c - 'a'];
        } // after this prefix, words can have any character, they just have to be complete words
        dfs(curr , ans , prefix);
        return ans;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new Node();
        for(string &s : products)
            add(s);
        string prefix;
        vector<vector<string>> ans;
        for(char &c : searchWord){
            prefix.push_back(c);
            ans.push_back(findSuggestion(prefix));
        }
        return ans;
    }
};