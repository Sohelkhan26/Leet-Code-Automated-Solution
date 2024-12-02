class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        vector<string> v;
        while(ss >> sentence)
            v.push_back(sentence);
        for(int idx = 0 ; idx < v.size() ; idx++){
            int n = searchWord.size() , m = v[idx].size() , i = 0 , j = 0;
            for(; i < m and j < m ; j++ , i++)
                if(v[idx][j] != searchWord[i])
                    break;
            if(i == n)
                return idx + 1;
        }
        return -1;
    }
};