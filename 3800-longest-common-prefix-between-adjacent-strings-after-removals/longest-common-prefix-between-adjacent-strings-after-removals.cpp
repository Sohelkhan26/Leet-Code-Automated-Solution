class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        auto solve = [&](string &a , string &b){
            int n = a.size() , m = b.size() , ans = 0;
            for(int i = 0 ; i < min(n , m) and a[i] == b[i] ; i++)
                ans++;
            return ans;
        };
        unordered_map <int,int> freq;
        multiset <int> all;

        auto add = [&](int len){
            if(++freq[len] == 1)
                all.insert(len);
        };

        auto remove = [&](int len){
            if(--freq[len] == 0){
                freq.erase(len);
                all.erase(len);
            }
        };

        int n = words.size();
        for(int i = 1 ; i < n ; i++){
            int len = solve(words[i - 1] , words[i]);
            add(len);
        }
        vector <int> ans;
        for(int i = 0 ; i < n ; i++){
            int len1 = -1 , len2 = -1 , len3 = -1;
            if(i > 0)
                len1 = solve(words[i - 1] , words[i]);
            if(i != n - 1)
                len2 = solve(words[i] , words[i + 1]);
            if(i - 1 >= 0 and i + 1 < n)
                len3 = solve(words[i - 1] , words[i + 1]);
            remove(len1);
            remove(len2);
            add(len3);
            ans.push_back(all.empty() ? 0 : *all.rbegin());
            add(len1) , add(len2) , remove(len3);
        }
        return ans;
    }
};