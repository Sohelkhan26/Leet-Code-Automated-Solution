class Solution {
public:
    string robotWithString(string s) {
        string t , ans;
        vector <int> count(26);
        for(char &c : s)
            count[c - 'a']++;
        int low = 0;
        for(char &c : s){
            t.push_back(c);
            count[c - 'a']--;
            while(low < 26 and count[low] == 0)
                low++;
            while(not t.empty() and t.back() <= low + 'a'){
                ans.push_back(t.back()); t.pop_back();
            }
        }
        return ans;
    }
};

/*
operation sequence can be : 1,2,1,2,1,1,1,1,2,2,2.... until both string are empty. Find lexicographical smallest string. We can append char taken from 's' immediately or hold it. There should be way to tell the lexicographical order of an char in 's'. If it comes first, immediately append to paper. Otherwise hold.
Is this problem that simple? I doubt so.
Seems like monotonic stack problem. Maintain increasing order, in hope to find a smaller character in future. If there is no smaller character in future. This didn't work out.
Store characters in a stack. for a character 'c' in "s" , if 'c' is <= lexicographicall smallest character in "s", we should append it immediately(1,2).
*/