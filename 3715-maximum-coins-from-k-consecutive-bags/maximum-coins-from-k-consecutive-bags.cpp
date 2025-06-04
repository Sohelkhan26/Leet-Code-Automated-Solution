class Solution {
public:
    using ll = long long;
    
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end()); 

        int n = coins.size();
        vector<ll> prefix(n + 1, 0); // prefix[i] = total coins in first i intervals
        vector <int> ending;
        for(int i = 0 ; i < n ; i++){
            int l = coins[i][0] , r = coins[i][1] , c = coins[i][2];
            prefix[i + 1] = prefix[i] + (1ll * (r - l + 1) * c); // prefix[i] = sum-of-coins([1..i - 1])
            ending.push_back(r) , ending.push_back(l + k - 1);
        }
        for(int i : ending)
            cout << i << ' ';
        auto solve = [&](int end){
            int low = 0 , high = n - 1 , mid , idx = -1;
            while(low <= high){
                mid = low + (high - low) / 2;
                if(coins[mid][0] <= end)
                    idx = mid , low = mid + 1;
                else high = mid - 1;
            }
            if(idx == -1)return 0ll;
            int l = coins[idx][0] , r = coins[idx][1] , c = coins[idx][2];
            ll full = prefix[idx] , partial = 1ll * (min(r , end) - l + 1) * c;
            return full + partial;
        };
        ll ans = 0;
        for(int &e : ending)
            ans = max(ans , solve(e) - solve(e - k));
        return ans;
    }
};


/*
k is too huge to iterate.
coins.size() is <= 10**5, can be iterated.
intervals are non-overlapping.
sort them ? then sliding window?
until end - start + 1 <= k ? 
[l , r , c] , c is always positive. So, no reason for leaving any bag in a interval.
there is no point in starting the window outside any [l , r] -> coins i.e: in the number line where there is no bags.
only consider possible ending points and then calculate window sum ending at those points.
Ending point can lie outside any interval or partially inside an interval.
Iterating coins array for each ending point is time consuming. So, use prefix sum and binary search.

*/