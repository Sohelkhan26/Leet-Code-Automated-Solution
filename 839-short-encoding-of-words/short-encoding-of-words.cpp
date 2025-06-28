class Solution {
public:
    struct Node{
        unordered_map <char,Node*> child;
        bool end = false;
    };
    Node* root;
    unordered_map <Node*,int> freq;
    void add(string &s){
        int n = s.size();
        Node* curr = root; 
        for(int i = n - 1 ; i >= 0 ; i--){
            if(not curr -> child.contains(s[i]))
                curr -> child[s[i]] = new Node();
            curr = curr -> child[s[i]];
        }
        freq[curr] = n + 1;
    }
    int minimumLengthEncoding(vector<string>& words) {
        root = new Node();
        for(string &s : words)
            add(s);
        int ans = 0;
        for(auto &[curr , count] : freq)
            if(curr -> child.empty())
                ans += count;
        return ans;
    }
};

/*
Too much details. Try to place a string as another strings suffix.
return min number of strings to represent words
plus number of # -> N
Trie? insert every word reversed?
*/