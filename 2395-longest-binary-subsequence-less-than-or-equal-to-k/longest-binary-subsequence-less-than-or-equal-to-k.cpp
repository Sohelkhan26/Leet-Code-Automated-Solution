class Solution {
public:
    int longestSubsequence(string s, int K) {
        int ans = s.size() , bit = 0;
        for(int i = s.size() - 1 ; i >= 0 ; i-- , bit++){
            if(s[i] == '1'){
                if(bit >= 31 or (1 << bit) > K)
                    ans--;
                if(bit < 31)
                    K -= (1 << bit);
            }
        }
        return ans;
    }
};


/*
Given a binary string and a positive integer k
return longest subseq (convereted to decimal) is <= k

subseq can contains leading 0(all zero possible? yeah , 1 <= k <= 1e9)
all 0 subseq always possible.
subseq can be only 32 length long. There could be more than 32 zero in MSB, that don't really matter, I don't know.

Greedy solution works:
Hard to be exact. I just had a hunch.
k in binary has these set bits : 0..0011111
s =                     00000111110..010001
we can pick 5 consecuitve ones or be greedy and take the first 2 ones
but in order to take the 5 ones, we have to discard 010001 from beginining
Even if there were no 0 in the middle this can be shown, to gain more 'x' later, we have to discard a length of at least 'x' from the beginning. 
It's not even guaranteed to gain 'x' (exactly count of set bits in k) by discarding a len >= x from beginning. 
*/