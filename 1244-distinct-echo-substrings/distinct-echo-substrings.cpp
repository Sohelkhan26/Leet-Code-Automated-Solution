class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set <string> ans;
        int n = text.size();
        for(int len = 1 ; len <= n / 2 ; len++){
            int count = 0;
            for(int left = 0 , right = len ; left + len < n ; left++ , right++){
                count = (text[left] == text[right] ? count + 1 : 0);
                if(count == len){
                    ans.insert(text.substr(left , len));
                    count--;
                }
            }
        }
        // for(const string &s : ans)
        //     cout << s << endl;
        return ans.size();
    }
};