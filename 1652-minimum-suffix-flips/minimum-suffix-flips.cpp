class Solution {
public:
    int minFlips(string target) {
        int flip = 0 , n = target.size();
        for(int i = 0 ; i < n ; i++)
            if(flip % 2 != (target[i] - '0'))
                flip++;
        return flip;
    }
};