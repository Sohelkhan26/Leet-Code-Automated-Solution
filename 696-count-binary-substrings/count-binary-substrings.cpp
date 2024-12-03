class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr = 1 , prev = 0 , n = s.size() , ans = 0;
        for(int i = 1 ; i < n ; i++){
            if(s[i] == s[i - 1])
                curr++;
            else{
                prev = curr;
                curr = 1;
            }
            ans += prev >= curr;
        }
        return ans;
    }
};
/*
Since the 0's and 1's have to be grouped consecutively, we only have to be concerned with the most recent two groups (curr, prev) at any time as we iterate through the input string (s). 
০০০০০ এরপর যত ১ পাওয়া যাবে সবগুলার জন্য ভ্যালিড সাবস্ট্রিং এর সংখ্যা এক করে বৃদ্ধি পাবে। তাই ans += prev >= curr;
*/
