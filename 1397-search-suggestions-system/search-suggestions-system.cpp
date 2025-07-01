class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin() , products.end());
        vector<vector<string>> ans;
        string prefix;
        for(char &c : searchWord){
            prefix.push_back(c);
            auto it  = lower_bound(products.begin() , products.end() , prefix);
            vector <string> suggested;
            for(int i = 0 ; it + i != products.end() and i < 3 ; i++){
                string &s = *(it + i);
                if(not s.starts_with(prefix))
                    break;
                suggested.push_back(s);
            }
            ans.push_back(move(suggested));
        }
        return ans;
    }
};