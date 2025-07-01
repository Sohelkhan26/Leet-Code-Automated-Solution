class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map <string, set<string>> all;
        for(string &s : products){
            string temp;
            for(char &c : s){
                temp.push_back(c);
                all[temp].insert(s);
            }
        }
        vector<vector<string>> ans;
        string temp;
        for(char &c : searchWord){
            temp.push_back(c);
            vector <string> curr; 
            auto it = all[temp].begin();
            for(int i = 0 ; i < 3 and it != all[temp].end() ; it++ , i++)
                curr.push_back(*it);
            ans.push_back(move(curr));
        }
        return ans;
    }
};