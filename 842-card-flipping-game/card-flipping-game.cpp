class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set <int> bad;
        int n = fronts.size() , ans = INT_MAX;
        for(int i = 0 ; i < n ; i++)
            if(fronts[i] == backs[i])
                bad.insert(fronts[i]);
        for(int i : fronts)
            if(not bad.contains(i))
                ans = min(ans , i);
        for(int i : backs)
            if(not bad.contains(i))
                ans = min(ans , i);
        return ans % INT_MAX;
    }
};

/*
fronts[i] and backs[i] can  be swapped any number of times.
An integer is called good if it never appears in the fronts array.
Return the minimum integer that is good. 

if fronts[i] == backs[i] then no matter what we do next, fronts[i] will never be good.
Other than these numbers, any number can be placed only on backs array by swapping.
*/