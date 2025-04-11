class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0 , y = 0;
        map <pair<int,int> , bool> prev;
        prev[{0 , 0}] = true;
        for(char &c : path){
            if(c == 'N')
                y--;
            else if(c == 'S')
                y++;
            else if(c == 'E')
                x++;
            else if(c == 'W')
                x--;
            if(prev.find({x , y}) != prev.end())
                return true;
            prev[{x , y}] = true;
        }
        return false;
    }
};