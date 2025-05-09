class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        vector <bitset<26>> unique;
        for(string &s : arr){
            bitset <26> mask;
            for(char &c : s)
                mask.set(c - 'a');
            if(mask.count() == s.size())
                unique.push_back(mask);
        }
        vector<bitset<26>> all = {bitset<26>()}; // contains all possible string that has unique characters.
        for(auto &s : unique){
            for(int i = all.size() - 1 ; i >= 0 ; i--){ // start from end because of push_back()
                if(not (all[i] & s).any()){ // .any() -> true , if any set bit is found
                    all.push_back(all[i] | s); // new string that has no duplicate
                    int len = all[i].count() + s.count();
                    ans = max(ans , len);
                }
            }
        }
        return ans;
    }
};