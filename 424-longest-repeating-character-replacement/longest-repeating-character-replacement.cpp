class Solution {
public:
    #define all(x) x.begin() , x.end()
    int characterReplacement(string s, int k) {
        unordered_map <char,int> freq;
        int n = s.size() , ans = 0;
        for(int left = 0 , right = 0 ; right < n ; right++){
            freq[s[right]]++;
            int Max = max_element(all(freq) , [&](auto a , auto b){
                return a.second < b.second;
            }) -> second;
            while(right - left + 1 - Max > k)
                freq[s[left++]]--;
            ans = max(ans , right - left + 1);
        }
        return ans;
    }
};

/*
Try to minimize replacement. So try to utilize the most occuring character.
If the replacement operation is > k, window should be shortened.
*/