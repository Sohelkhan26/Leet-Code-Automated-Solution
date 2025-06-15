class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector <int> minCost(nums);
        long long ans = accumulate(minCost.begin() , minCost.end() , 0ll);
        for(int rotation = 1 ; rotation < n ; rotation++){
            for(int i = 0 ; i < n ; i++){
                int j = (i - rotation + n) % n;
                minCost[i] = min(minCost[i] , nums[j]);
            }
            long long total = accumulate(minCost.begin() , minCost.end() , 0ll) + 1ll * rotation * x;
            ans = min(ans , total);
        }
        return ans;
    }
};


/*
Seems like a BFS or Dijkstra problem. 
0 step we can buy at original cost.
1 step -> shift all cost by 1 to the right and add 1 * x
n'th step -> shift all cost by 1 to the right and add n * x
How many candy to take at the i'th step? 1 is not optimal. Take all candy with the smallest cost.

saw a hint. There could be n rotations. As we have to rotate simultaneously it makes sense. There could be one minimum cost and we have to repeat for n times.
Since rotation happens simultaneously, extra cost for rotation is rotation * x
It is constant for all indices. 
And nums[i] = nums[i - rotation]
*/