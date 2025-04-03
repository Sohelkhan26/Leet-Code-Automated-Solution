class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size() , notSame = 0;
        vector <int> a(26) , b(26);
        for(int i = 0 ; i < n ; i++)
            a[s1[i] - 'a']++ , b[s2[i] - 'a']++ , notSame += (s1[i] != s2[i]);
        for(int i = 0 ; i < a.size() ; i++)
            if(a[i] != b[i])
                return false;
        return notSame <= 2;
    }
};