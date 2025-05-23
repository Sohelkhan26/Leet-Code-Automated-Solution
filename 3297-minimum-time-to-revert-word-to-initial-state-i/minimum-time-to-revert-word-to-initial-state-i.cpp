class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size() , ans = 1;
        for(int i = k ; i < n ; i += k , ans++){
            if(word.substr(0 , n - i) == word.substr(i))
                return ans;
        }
        return ans;
    }
};

/*
At least one operation is performed. Then we have to check how many operation do we need to revert to initial string.
Appended character could be anything. So, we can leave them blank and fill them at the end. When prefix of word and suffix of modified word matches no need for further operation. 
word = abacaba , k = 3
caba_ _ _ ,
a _ _ _ _ _ _ , both starting matches, so we fill them as we want. 
*/