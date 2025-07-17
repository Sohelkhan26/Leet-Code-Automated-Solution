class Solution {
public:
    struct Node {
        Node* child[26] = {};
        int index = -1;
        vector<int> palindromes; // store indices of palindromic suffix
    } *root = new Node();

    bool palindrome(const string& s, int i, int j) {
        while(i <= j)
            if(s[i++] != s[j--])
                return false;
        return true;
    }

    void add(const string &s , int idx){
        Node* curr = root;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            int j = s[i] - 'a';
            if(palindrome(s , i , n - 1)) // store variable length suffix palindrome
                curr -> palindromes.push_back(idx);
            if(curr -> child[j] == nullptr)
                curr -> child[j] = new Node();
            curr = curr -> child[j];
        }
        curr -> index = idx; // mark end of word
        curr -> palindromes.push_back(idx); // empty suffix palindrome present at idx
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        for (int i = 0; i < words.size(); i++)
            add(words[i], i);

        vector<vector<int>> ans;
        for(int i = 0 ; i < words.size() ; i++){
            string &word = words[i];
            Node* curr = root;
            int n = word.size();
            for(int j = n - 1 ; j >= 0 and curr ; j--){
                if(curr -> index != -1 and curr -> index != i and palindrome(word , 0 , j)) // current words suffix matches some other whole words prefix, current word is bigger, so check if rest of word(prefix of current word) is palindrome too. i.e: words[i] = llss other word = lls
                    ans.push_back({curr -> index , i});
                curr = curr -> child[word[j] - 'a'];
            }
            if(curr) 
                for(int j : curr -> palindromes) // current word smaller and some other word is bigger. i.e: words[i] = lls other word = llsss. rest of the other word is also a palindrome, that's why it's stored here.
                    if(j != i)
                        ans.push_back({j , i});
        }

        return ans;
    }
};
