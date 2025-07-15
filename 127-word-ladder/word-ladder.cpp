class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> avail(wordList.begin() , wordList.end());
        queue <string> q;
        q.push(beginWord);
        int time = 0;
        while(not q.empty()){
            int len = q.size();
            time++;
            while(len--){
                string s = q.front(); q.pop();
                if(s == endWord)
                    return time;
                for(char &c : s){
                    char t = c;
                    for(char d = 'a' ; d <= 'z' ; d++){
                        c = d;
                        auto it = avail.find(s);
                        if(it != avail.end()){
                            q.push(*it);
                            avail.erase(it);
                        }
                    }
                    c = t;
                }
            }
        }
        return 0;
    }
};