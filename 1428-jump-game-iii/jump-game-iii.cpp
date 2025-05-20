class Solution {
public:
    unordered_set <int> vis;
    bool canReach(vector<int>& arr, int i) {
        if(i >= 0 and i < arr.size() and vis.insert(i).second) // insert() returns false if element already exists
            return arr[i] == 0 or canReach(arr , i + arr[i]) or canReach(arr , i - arr[i]);
        return false;
    }
};