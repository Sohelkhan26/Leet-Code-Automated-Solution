class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size() , ans = 0 , left , right;
        unordered_map <char,int> freq;
        auto valid = [&](){
            for(char c : {'a' , 'e' , 'i' , 'o' , 'u'})
                if(not freq.contains(c))
                    return false;
            return true;
        };
        char prev = word[0];
        for(left = 0 , right = 0 ; right < n ; right++){
            if(prev > word[right]){
                if(valid())
                    ans = max(ans , right - left);
                left = right;
                freq.clear();
            }
            freq[word[right]]++;
            prev = word[right];
        }
        if(valid())
            ans = max(ans , right - left);
        return ans;
    }
};