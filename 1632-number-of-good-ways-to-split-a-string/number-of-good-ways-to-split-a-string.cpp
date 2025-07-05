class Solution {
public:
    int numSplits(string s) {
        unordered_map <char,int> left , right;
        int ans = 0;
        for(char &c : s)
            right[c]++;
        for(char &c : s){
            left[c]++;
            if(--right[c] == 0)
                right.erase(right.find(c));
            if(left.size() == right.size())
                ans++;
        }
        return ans;
    }
};