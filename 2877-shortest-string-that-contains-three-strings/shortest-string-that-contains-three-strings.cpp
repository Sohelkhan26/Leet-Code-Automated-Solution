class Solution {
public:
    string minimumString(string a, string b, string c) {
        vector <string> v = {a , b , c};
        vector <int> comb = {0 , 1 , 2};
        string ans(301 , 'z');
        auto merge = [&](const string &a , const string &b){
            if(a.find(b) != string::npos)
                return a;
            int n = a.size() , m = b.size();
            for(int len = min(n , m) ; len >= 0 ; len--)
                if(a.ends_with(b.substr(0 , len)))
                    return a + b.substr(len);
            return a + b;
        };
        do{
            a = v[comb[0]] , b = v[comb[1]] , c = v[comb[2]];
            string ab = merge(a , b) , abc = merge(ab , c);
            if(abc.size() < ans.size() or (abc.size() == ans.size() and abc < ans))
                ans = abc;
        }while(next_permutation(comb.begin() , comb.end()));
        return ans;
    }
};