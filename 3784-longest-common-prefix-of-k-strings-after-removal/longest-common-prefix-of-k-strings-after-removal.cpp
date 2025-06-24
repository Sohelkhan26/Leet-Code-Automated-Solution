class Solution {
public:
    int k;
    struct Node{
        Node* child[26] = {};
        int count = 0;
        bool isEnd = false;
    };
    unordered_map <int,int> freq;
    set <int> best;
    Node* root;
    void add(const string &s){
        Node* curr = root;
        for(int i = 0 ; i < s.size() ; i++){
            if(curr -> child[s[i] - 'a'] == nullptr)
                curr -> child[s[i] - 'a'] = new Node();
            curr = curr -> child[s[i] - 'a'];
            curr -> count++;
            if(curr -> count >= k) // more than k string has same prefix with length i + 1
                if(++freq[i + 1] == 1) // increase frequency of i + 1 length prefix
                    best.insert(i + 1); // insert into set only first time
        }
        curr -> isEnd = true;
    }
    void remove(const string &s){
        Node* curr = root;
        for(int i = 0 ; i < s.size() ; i++){
            curr = curr -> child[s[i] - 'a'];
            curr -> count--;
            if(curr -> count == k - 1)  
                if(--freq[i + 1] == 0)  
                    best.erase(best.find(i + 1));
        }
        curr -> isEnd = false;
    }
    vector<int> longestCommonPrefix(vector<string>& words, int K) {
        root = new Node();
        k = K;
        vector <int> ans;
        for(const string &s : words)
            add(s);
        for(const string &s : words){
            remove(s);
            if(best.size() == 0)
                ans.push_back(0);
            else
                ans.push_back(*best.rbegin());
            add(s);
        }
        return ans;
    }
};

/*
return an array of same length as words
for each indix, remove words[i] and out of remaining words[i] select any k strings and find longest common prefix
obviously we would like to choose the best strings that yields maximum answer[i].

what could be the most basic approach?
use a trie and remove words[i], and check rest. what about k strings? Then start DP?
we can either take i'th string or skip it. have to keep track of i,k

Add all word[i] into trie and keep track of frequency
if a frequency of a prefix is >= k store it in a map
It stores count of all prefix lengths with frequency more than k

Use set to store all lengths of prefix that has frequency more than k

go through each word and erase it from trie, if freq of any prefix go below k decrease it's frequency in map. If freq of a len becomes zero remove from set

after each removal largest length stored in the set is the answer.
*/