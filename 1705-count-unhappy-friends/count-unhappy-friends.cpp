class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        unordered_map <int,int> pairing;
        for(auto &p : pairs)
            pairing[p[0]] = p[1],
            pairing[p[1]] = p[0];
        auto find = [&](int x , int y){
            for(int u : preferences[x]){
                if(u == y)
                    return false;
                bool unhappy = false;
                for(int v : preferences[u]){
                    if(v == pairing[u])
                        break;
                    if(v == x)
                        unhappy = true;
                }
                if(unhappy)
                    return true;
            }
            return false;
        };
        int ans = 0;
        for(auto &it : pairs){
            int x = it[0] , y = it[1];
            ans += find(x , y);
            ans += find(y , x);
        }
        return ans;
    }
};

/*
Such a trick problem. 
Preference of every person is given.
A person 'x' is unhappy if there is a person 'u' who is preferred over 'x's current pairing and that person 'u' also prefers 'x' over his current pairing.

Constraint is small. Brute force will pass.
For each pairs [x,y], 
traverse over 'x's preferences, before reaching 'y'
Now for each preference 'u' , traverse 'u's preferance list, if
'x' is before 'u's pairing(the person 'u' is paired with), then 'x' is unhappy.
'u' also prefers 'x' over his current pairing.
*/