class Solution {
public:
    int countOfSubstrings(string s, int k) {
        // unordered_map <char,int> mp;
        // int n = s.size() , ans = 0 , count = 0;
        auto vowel = [&](char c){
            return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
        };
        // for(int left = 0 , right = 0 ; right < n ; right++){
        //     if(vowel(s[right]))
        //         mp[s[right]]++;
        //     else count++;
        //     while(count > k){
        //         if(vowel(s[left])){
        //             if(--mp[s[left]] == 0)
        //                 mp.erase(mp[s[left]]);
        //         }
        //         else count--;
        //         left++;
        //     }
        //     if(mp.size() == 5)
        //         ans++;
        // }   
        // return ans;
        int n = s.size() , ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                int c = 0;
                set <char> st;
                for(int k = i ; k <= j ; k++)
                    if(vowel(s[k]))
                        st.insert(s[k]);
                    else c++;
                ans += (st.size() == 5 and c == k);
            }
        }
        return ans;
    }
};