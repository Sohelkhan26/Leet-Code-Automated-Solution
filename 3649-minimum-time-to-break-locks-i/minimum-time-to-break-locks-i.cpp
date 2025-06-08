class Solution {
public:
    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();
        function<int(int,int)> solve = [&](int mask , int x){
            if(mask == (1 << n) - 1)
                return 0;
            int cost = 1e9;
            for(int i = 0 ; i < n ; i++){ // open the i'th lock
                if(mask & (1 << i))
                    continue;
                cost = min(cost , (int)ceil((strength[i] * 1.0) / x) + solve(mask | (1<<i) , x + k));
            }
            return cost;
        };  
        return solve(0 , 1);
    }
};
/*
Tried Binary search with greedy. don't work.
order of picking which lock to open effects the total time.
constraint is low, try all possible combination. at time i, 
consider opening any lock out of n, solve the subproblem and return the min.
*/