class Solution {
public:
    int maxSubstrings(string word) {
        unordered_map <char,int> prev;
        int n = word.size() , ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(prev.contains(word[i])){
                if(i - prev[word[i]] >= 3)
                    prev.clear() , ans++;
            }else prev[word[i]] = i;
        }
        return ans;
    }
};

/*
s = "abcdebcdefca"
There is no possibility , if we choose this substring, we loose some other substring for the condition: "substring should be non-intersecting"
If we choose the whole string, start=end='a'
we could loose "bcdeb" "cdefc"
instead of "bcdeb" we could 
choose "debcd" This could have been smaller But we can't form substring from middle
So, maximizing substring is not possible. We choose the smallest substring and that's it.
*/