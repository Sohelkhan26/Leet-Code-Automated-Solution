class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map <int,bool> seen;
        for(int i : arr)
            if(seen.find(i * 2) != seen.end() or (i % 2 == 0 and seen.find(i / 2) != seen.end()))
                return true;
            else seen[i] = true;
        return false;
    }

};