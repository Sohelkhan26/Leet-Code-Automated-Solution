class Solution {
public:
    int minimumPushes(string word , int ans = 0) {
        vector <int> count(26);
        for(char &c : word)
            count[c - 'a']++;
        sort(count.rbegin() , count.rend());
        for(int i = 0 ; i < 26 and count[i] != 0 ; i++)
            ans += (i / 8 + 1) * count[i];
        return ans;
    }
};