class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set <string> origin(wordlist.begin() , wordlist.end());
        unordered_map <string,string> cap , vowel;
        auto toLow = [&](string s){
            for(char &c : s)
                c = tolower(c);
            return s;
        };
        auto change = [&](string s){
            s = toLow(s);
            for(char &c : s)
                if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
                    c = '!';
            return s;
        };
        for(string s : wordlist){
            string l = toLow(s) , v = change(s);
            cap.insert({l , s});
            vowel.insert({v , s});
        } 
        for(string &q : queries){
            if(origin.contains(q))  
                continue;
            string l = toLow(q) , v = change(q);
            if(cap.contains(l))
                q = cap[l];
            else if(vowel.contains(v))
                q = vowel[v];
            else q = "";
        }
        return queries;
    }
};

/*
If queried word matches exactly return it
Otherwise 2 case:
1. check with every word (by either lower case or upper case) if they match return the original
2. If step 1 fails, change any vowel to any other vowel and again check word and return the original if found. Also case insensitive.

Great problem according to me. 
Since we have return first match, only store the first one. 
insert function in map don't overwrite, mp[i] = j over writes i'th key
Since a vowel can be changed to any other vowel, any vowel is a "don't care" option, change it some other non alphabet.
*/