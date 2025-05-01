class Solution {
public:
    vector <pair<int,int>>  dir = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
    string alphabetBoardPath(string t) {
        vector <string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        int len = 5 , i = 0 , j = 0;
        auto bfs = [&](char target) -> string{
            queue <pair<pair<int,int> , string>> q;
            q.push({{i , j} , ""});
            auto valid = [&](int x , int y){
                return min(x , y) >= 0 and x < len and y < len;
            };
            set <pair<int,int>> vis = {{i , j}};
            while(not q.empty()){
                int n = q.size();
                while(n--){
                    auto [c , path] = q.front() ; q.pop();
                    int x = c.first , y = c.second;
                    if(board[x][y] == target){
                        i = x , j = y;
                        return path;
                    }
                    for(int i = 0 ; i < 4 ; i++){
                        int newX = x + dir[i].first , newY = y + dir[i].second;
                        if((newX == 5 and newY == 0) or valid(newX , newY)){
                            if(vis.contains({newX , newY}))continue;
                            vis.insert({newX , newY});
                            string temp = path;
                            if(i == 0)
                                path += 'U';
                            else if(i == 1)
                                path += 'D';
                            else if(i == 2)
                                path += 'L';
                            else path += 'R';
                            q.push({{newX , newY} , path});
                            path = temp;
                        }
                    }
                }
            }
            return "";
        };
        string ans;
        for(char &c : t)
            ans += (bfs(c) + string(1 , '!'));
        return ans;
    }
};