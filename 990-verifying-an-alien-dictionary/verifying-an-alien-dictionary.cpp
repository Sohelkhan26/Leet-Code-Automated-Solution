class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map <char,char> mapping;
        char a = 'a';
        for(char c : order)
            mapping[c] = a++;
        for(string &word : words)
            for(char &c : word)
                c = mapping[c];
        return is_sorted(words.begin() , words.end());
    }
};
/*
Build a transform mapping from order,
Find all alien words with letters in normal order.

For example, if we have order = "xyz..."
We can map the word "xyz" to "abc" or "123"
*/