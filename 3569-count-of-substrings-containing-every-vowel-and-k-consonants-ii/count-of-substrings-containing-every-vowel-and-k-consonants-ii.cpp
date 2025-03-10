class Solution {
public:
    string vw = "aeiou";
    long long countAtLeastK(string &word , int k){
        long long ans = 0 , vowel = 0 , count[6] = {0} , n = word.size();
        for(int left = 0 , right = 0 ; right < n ; right++){
            int i = vw.find(word[right]) + 1;
            vowel += (++count[i] == 1 and i); // vowel and it's the first one
            while(vowel == 5 and count[0] >= k){
                ans += n - right;
                int i = vw.find(word[left++]) + 1;
                vowel -= (--count[i] == 0 and i);
            }
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return countAtLeastK(word , k) - countAtLeastK(word , k + 1);
    }
};