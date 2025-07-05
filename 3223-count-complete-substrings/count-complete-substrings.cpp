class Solution {
public:
    int solve(int start , int end , string &word , int k){
        int ans = 0; 
        for(int unique = 1 ; unique <= 26 and unique * k <= end - start + 1 ; unique++){ 
            vector <int> count(26);
            int validChar = 0 , window = unique * k;
            for(int left = start , right = start ; right <= end ; right++){
                char c = word[right];
                count[c - 'a']++;
                if(count[c - 'a'] == k) // each unique character should occur k times exactly
                    validChar++;
                else if(count[c - 'a'] == k + 1) // > k is wrong. 
                    validChar--; // then extra deletion is performed.
                if(right - left + 1 > window){
                    c = word[left++];
                    if(count[c - 'a'] == k) 
                        validChar--;
                    else if(count[c - 'a'] == k + 1)
                        validChar++;
                    count[c - 'a']--;
                }
                if(validChar == unique)
                    ans++;
            }
        }
        return ans;
    }
    int countCompleteSubstrings(string word, int k) {
        int n = word.size() , ans = 0 , start = 0;
        for(int i = 1 ; i <= n ; i++){
            if(i == n or abs(word[i] - word[i - 1]) > 2)
                ans += solve(start , i - 1 , word , k) , start = i;
        }
        return ans;
    }
};

/*
Good sliding window problem. 
Given a string count good substrings. 
Good substring:
1. each character in substring occurs exactly 'k' times
2. abs(adjacent char) <= 2

Problem can be divided into subproblems by dividing the string based on condition 2.
If adjacent character differ by more than 2, they can't be expanded into good substring in the future.
*/