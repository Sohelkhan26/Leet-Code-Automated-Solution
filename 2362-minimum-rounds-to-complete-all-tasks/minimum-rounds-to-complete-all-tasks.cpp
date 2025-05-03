class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        unordered_map <int,int> freq;
        for(int &i : tasks)
            freq[i]++;
        for(auto &[key , val] : freq){
            if(val == 1)
                return -1;
            ans += val / 3 + not (val % 3 == 0);
        }
        return ans;
    }
};

/*
Interesting problem. We can do either 2 or 3 tasks, not more not less.
If group has 1 task return -1; Group greater than 3 can be broken down to 2x + 3y. To make minimum operation , 3 task should be prioritized. 
If freq is divisible by 3 take freq / 3, othewise we are left with:
1 extra task : break a previous 3 group and make 2 2 groups. add 1 to operation
2 extra task : do the 2 task. add 1 to operation.
*/