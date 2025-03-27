class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int total = 0 , n = encoded.size() + 1;
        for(int i = 1 ; i <= n ; i++)
            total ^= i;
        for(int i = 1 ; i < n ; i += 2)
            total ^= encoded[i];
        vector <int> ans = {total};
        for(int i : encoded)
            ans.push_back(total xor i) , total ^= i;
        return ans;
    }
};

/*
Determine the first element and rest is golden.
First element = xor(i) ^ xor(j) where i = 2..n and j = 1..n
xor(i) is xor(encoded[k]) where k = odd (1,3,5...)
Now we found a off our sequence a , b , c , d
encoded =                        a^b  b^c c^d
so xor the first element with elements from encoded.
*/