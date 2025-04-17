class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0 , prev = 0 , n = values.size();
        for(int i = 0 ; i < n ; i++){
            ans = max(ans , prev + values[i] - i);
            prev = max(prev , values[i] + i);
        }
        return ans;
    }
};

/*
find such pair such that (nums[i] + i) + (nums[j] - j) is maximized. i != j
8 1 5 2 6
8 2 7 5 10 nums[i] + i
8 0 3 -1 2 nums[j] - j
Take the biggest value from two resulting array such that i < j 
As we move forward all spots will be 1 distance further.
Greedy. Keep track of previous best nums[i] + i and compare with current nums[j] - j
Almost similar to Best time to buy and sell stock, in this one we keep track of previous max value.
*/