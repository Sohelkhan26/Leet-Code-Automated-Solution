class Solution {
public:
    bool queryString(string s, int n) {
        for(int i = 1 ; i <= n ; i++){
            string num = bitset<32>(i).to_string();
            cout << num << endl;
            if(s.find(num.substr(num.find('1'))) == -1)
                return false;
        }
        return true;
    }
};