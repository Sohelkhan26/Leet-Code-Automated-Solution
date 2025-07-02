class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto f = [&](string &s){
            vector <int> count(26);
            for(char &c : s)
                count[c - 'a']++;
            for(int &i : count)
                if(i > 0)
                    return i;
            return -1;
        };
        vector <int> freq , ans;
        for(string &s : words)
            freq.push_back(f(s));
        sort(freq.begin() , freq.end());
        for(string &s : queries){
            int target = f(s); 
            ans.push_back(freq.end() - upper_bound(freq.begin() , freq.end() , target));
        }
        return ans;
    }
};