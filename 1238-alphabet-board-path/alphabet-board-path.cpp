class Solution {
public:
    string alphabetBoardPath(string target) {
        unordered_map <char,pair<int,int>> pos;
        for(int i = 0 ; i < 26 ; i++)
            pos[i + 'a'] = {i / 5 , i % 5};
        int x = 0 , y = 0;
        string ans;
        for(char &c : target){
            auto d = pos[c];
            int newX = d.first , newY = d.second;
            if(pair<int,int> {x , y} == pos['z'] and c != 'z')
                ans.append("U") , x--; // prev = 'z' so go up.
            if(y < newY)ans += string((newY - y) , 'R');
            if(y > newY)ans += string((y - newY) , 'L');
            if(x < newX)ans += string((newX - x) , 'D');
            if(x > newX)ans += string((x - newX) , 'U');
            ans.append("!");
            x = newX , y = newY;
        }
        return ans;
    }
};

/*
Harder approach is BFS.
It asks for min moves, not necessarily BFS is required for that.
Manhattan distance is the shortest path. i.e : dx , dy
Only one edge case: 'z'
If we are currently at 'z' we can't move left or right or down. Only move is up. So, if prev was 'z' and now we have to go to other character than 'z' we must go up. 
*/