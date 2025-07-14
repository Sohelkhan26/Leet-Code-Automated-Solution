class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set <string> seen;
        string sub;
        vector<string> ans;
        for(char &c : s){
            sub.push_back(c);
            if(not seen.contains(sub))
                seen.insert(sub) , ans.push_back(move(sub));
        }
        return ans;
    }
};