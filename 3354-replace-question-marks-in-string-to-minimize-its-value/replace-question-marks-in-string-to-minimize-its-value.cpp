class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> count(26);
        int n = s.size();
        for(char &c : s)
            if(c != '?')
                count[c - 'a']++;
        auto smallest = [&]() -> char {
            int mn = *min_element(count.begin(), count.end());
            for (int i = 0; i < 26; i++) {
                if (count[i] == mn) { // find smallest freq char
                    count[i]++;  // don't forget to increase freq
                    return (char)(i + 'a');
                }
            }
            return 'a';  // fallback, never reached
        };
        vector <char>ans;
        for (int i = 0; i < n; i++) 
            if (s[i] == '?') 
                ans.push_back(smallest());
            
        sort(ans.begin() , ans.end()); // for lexicographical case
        int i = 0;
        for(char &c : s)
            if(c == '?')
                c = ans[i++];
        return s;
    }
};


/*
when n > 26 ? any char will increase cost[i], to minimize cost, use char which has min count so far.
lexicographical case ? only count of freq[s[i]] increase the cost, so, using it at any index is good. so, we can sort and use the smallest chars first.
AT first i increased count as i traversed for char other than ?, it's not valid, what if 'a' occurs after index i?
"abcdefghijklmnopqrstuvwxy??"
we can use 'za' or 'az' which one should we use? of course 'az'
*/