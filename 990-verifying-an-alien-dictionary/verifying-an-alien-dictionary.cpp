class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map <char , int> mapping;
        for(int i = 0 ; i < order.size() ; i++)
            mapping[order[i]] = i;
        auto check = [&](string a , string b) -> bool{
            int n = a.size() , m = b.size();
            for(int i = 0 ; i < n and i < m ; i++)
                if(mapping[a[i]] != mapping[b[i]])
                    return mapping[a[i]] < mapping[b[i]];
            return n <= m;
        };
        for(int i = 0 ; i < words.size() - 1 ; i++){
            if(not check(words[i] , words[i + 1]))
                return false;
        }
        return true;
    }
};
/*
If a sequence of words is sorted, then each adjacent word of the sequence must also be sorted. In the given question, while comparing if two words are sorted, we just need to compare mp[letter1] and mp[letter2] (instead of direct letter1 and letter2 that we would have done if it was normal english alphabetical ordering). Now, while checking if string a, b are lexicographically sorted, they are -

  \U0001f449 Lexicographically Sorted when -
✦ If at first mismatch, mp[a[i]] < mp[b[i]], or
✦ If each letters of both words match and length(a) <= length(b)

  \U0001f449 Not Lexicographically Sorted when -
✦ If at first mismatch, mp[a[i]] > mp[b[i]], or
✦ If each letters of both words match and length(a) > length(b).

With this, we can proceed to check if each adjacent words are lexicographically sorted and return true if all are found to be sorted.
*/