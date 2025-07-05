class Solution {
public:
    string minWindow(string s, string t) {
        vector <int> window(128) , tFreq(128);
        for(char &c : t)
            tFreq[c]++;
        int n = s.size() , len = n + 1 , start = 0 , target = t.size() , formed = 0;
        for(int left = 0 , right = 0 ; right < n ; right++){
            char c = s[right];
            window[c]++;
            if(tFreq[c] > 0 and window[c] <= tFreq[c]) 
                formed++;
            while(formed == target){ // good subarray found, time to shrink window.
                if(right - left + 1 < len)
                    len = right - left + 1 , start = left;
                c = s[left++];
                if(tFreq[c] > 0 and window[c] <= tFreq[c]) // deleting extra frequency won't make the window valid. Invalid only when we don't have enough of c 
                    formed--;
                window[c]--;
            }
        }
        return len == n + 1 ? "" : s.substr(start , len);
    }
};

/*
Very interesting problem. 
Find shortest substring from s, such that it contains all characters from t(including duplicates)
s[i],t[i] can be upper/lowercase.
Sliding window? expand until good substring found. 
Then shrink window until window becomes invalid, and calculate answer.
But using comparing and storing frequency using map gives TLE.
So, have to use a clever technique.
Keep track if every character frequency of 't' is included in the current window by a single variable. "formed"
And use a vector of size 128 instead of map.
increase formed when for a character 'c'
our window needs that character to be equal to tFreq[c] i.e : window[c] <= tFreq[c]
because our window can have more than needed of the character 'c' but extra ones don't help us in finding good subarray. Same codition for shrinking the window.
*/