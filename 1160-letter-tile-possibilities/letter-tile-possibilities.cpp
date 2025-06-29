class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector <int> count(26);
        for(char &c : tiles)
            count[c - 'A']++;
        function<int()> dfs = [&](){
            int total = 0;
            for(int i = 0 ; i < 26 ; i++){
                if(count[i] == 0)
                    continue;
                total++;
                count[i]--;
                total += dfs();
                count[i]++;
            }
            return total;
        };
        return dfs();
    }
};