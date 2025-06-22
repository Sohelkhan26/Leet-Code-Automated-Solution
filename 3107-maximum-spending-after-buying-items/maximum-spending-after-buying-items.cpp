class Solution {
public:
    typedef pair<int,int> P;
    long long maxSpending(vector<vector<int>>& values) {
        long long ans = 0;
        int n = values.size() , m = values[0].size();
        priority_queue < array<int,3> , vector<array<int,3>> , greater<> > pq;
        for(int i = 0 ; i < n ; i++)
            pq.push({values[i][m - 1] , i , m - 1});
        for(int day = 1 ; day <= m * n ; day++){
            auto it = pq.top(); pq.pop();
            int val = it[0] , x = it[1] , y = it[2];
            if(y - 1 >= 0)
                pq.push({values[x][y - 1] , x , y - 1});
            ans += (1ll * val * day);
        }
        return ans;
    }
};

/*
m * n grid given.
m shops, each have n items.
each row sorted in non-increasing manner.
each day buy 1 item from 1 shop
on d'th day:
pick any shop, buy the last item that was not bought before,
for values[i][j] * d
items pairwise different, same item can be bought from diff shop.
return max amount you can spend.

use min heap for each shop and take the least valuable items as early as possible?
Is the solution this easy?
*/