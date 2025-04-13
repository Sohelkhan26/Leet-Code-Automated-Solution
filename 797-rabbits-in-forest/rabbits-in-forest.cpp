class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0 , n = answers.size();
        unordered_map <int,int> freq;
        for(int &i : answers)
            if(++freq[i] == i + 1)
                ans += i + 1 , freq.erase(i);
        for(auto &[n , _ ] : freq)
                ans += (n + 1);
        return ans;
    }
};

/*
Only one edge case: If rabit with more than 1 color have same number of rabbits.
For say there are 3 blue and 3 red rabbits.
answers can be [2 , 2 , 2 , 2]
So, when count of some number "x" exceeds that number (i.e freq[x] >= x + 1) that rabit should be of new color.
Otherwise only either all the rabbits didn't answer or all of them did. Either way rabbit count is (x + 1).
In short only (x + 1) same number should exist, if the same number crosses this threshold a new color is introduced.
*/