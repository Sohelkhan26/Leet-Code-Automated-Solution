class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map <int,int> freq;
        int ans = 0;
        for(int &i : time){
            i %= 60;
            ans += freq[i == 0 ? i : 60 - i];
            freq[i]++;
        }
        return ans;
    }
};

/*
(a + b) % val = (a % val + b % val) % val
each number can be either multiple of 60 or not.
If a number is multiple of 60 then i % 60 = 0 this number i will make a valid pair with all numbers that were previously a mutliple of 60
Otherwise it will make valid pair with all numbers = 60 - i that have come before it. So that i + 60 - i = 60 which is a mutliple of 60
*/