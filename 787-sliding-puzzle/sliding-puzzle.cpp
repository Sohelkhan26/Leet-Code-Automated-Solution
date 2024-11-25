/*
Index of board:
0 1 2
3 4 5
Allowed move from one index to another:
0 -> 1 , 3
1 -> 0 , 2 , 4
2 -> 1 , 5
3 -> 0 , 4
4 -> 3 , 1 , 5
5 -> 2 , 4
We can represent node of the board as state. A zero can be swapped with it's adjacent cells thus going to a different node. We have to find the least distance to the final node 123450 from the given node in board 2D vector.
*/
class Solution {
public:
    vector<vector<int>> dir = {
        {1 , 3},
        {0 , 2 , 4},
        {1 , 5},
        {0 , 4},
        {1 , 3 , 5},
        {2 , 4}
    };
    int slidingPuzzle(vector<vector<int>>& board) {
        string state;
        for(auto it : board)
            for(int i : it)
                state.push_back(i + '0');
        queue <pair<string,int>> q;
        q.push({state , state.find('0')});
        unordered_set <string> vis;
        vis.insert(state);
        int level = 0;
        while(not q.empty()){
            int n = q.size();
            while(n--){
                auto [state , i] = q.front(); q.pop();
                if(state == "123450")
                    return level;
                for(int j : dir[i]){
                    swap(state[i] , state[j]);
                    if(not vis.contains(state)){
                        q.push({state , j}); // Now the adjacent index contains 0
                        vis.insert(state);
                    }
                    swap(state[i] , state[j]); // This swap is needed to go back to initial state
                }
            }
            level++;
        }
        return -1;
    }
};