class Solution {
public:
    int minimumLength(string s) {
        vector <int> count(26);
        for(char c : s)
            count[c - 'a']++;
        int ans = 0;
        for(int i : count){
            if(i >= 3){
                if(i % 2 == 0)
                    ans += 2;
                else ans++;
            }else ans += i;
        }
        return ans;
    }
};