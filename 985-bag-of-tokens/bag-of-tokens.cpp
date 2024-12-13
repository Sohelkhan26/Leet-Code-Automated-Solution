class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin() , tokens.end());
        int ans = 0 , score = 0 , n = tokens.size();
        for(int small = 0 , big = n - 1 ; small <= big ; ){
            if(power >= tokens[small]){
                power -= tokens[small++];
                ans = max(ans , ++score);
            }else if(score > 0){
                power += tokens[big--];
                score--;
            }else break;
        }
        return ans;
    }
};

/*
Not sure why do we need extra ans variable. I wrote the same code without the ans variable , I directly returned the score but that code fails for the third testcase.

I do get how does the ans variable works but it didn't come to my mind. how do I make this come to my mind? What's the intuition?

Ignore the details given in the problem. Focus on Input given and required output.

Input: A number array , for each element we can add it to power and score++
Or , power += token[i] and score-- 
To do the first operation condition is given : power >= tokens[i]
and Second condition : score > 0

Every equation stays the same and to maximize the score we need to use the smallest tokens to gain score so that power -= tokens[i] is minimized
And use bigger tokens to lose score so that power += tokens[i] is maximized.
*/