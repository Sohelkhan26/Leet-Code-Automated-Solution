class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        auto check = [&](vector<vector<int>> a) -> bool{
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < m ; j++)   
                    if(a[i][j])
                        return false;
            return true;
        }; // check if it's a zero matrix
        auto hash = [&](vector<vector<int>> a) -> int{
            int value = 0;
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < m ; j++)
                    value = value * 10 + a[i][j];
            return value;
        }; // to track visited state instead of using the whole matrix , use hash value
        queue < vector<vector<int>> > q;
        unordered_set <int> vis;
        q.push(mat);
        vis.insert(hash(mat));
        int flip = 0;
        while(not q.empty()){
            int len = q.size();
            while(len--){
                auto a = q.front(); q.pop();
                auto temp = a;
                if(check(a))
                    return flip;
                for(int i = 0 ; i < n ; i++){
                    for(int j = 0 ; j < m ; j++){
                        a[i][j] ^= 1; // for every position in the matrix we can flip it and it's neighbours if they exist.
                        for(auto [di , dj] : vector<pair<int,int>> {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}}){
                            int newi = i + di , newj = j + dj; // flipping neighbours if exists
                            if(min(newi , newj) >= 0 and newi < n and newj < m){
                                a[newi][newj] ^= 1;
                            }
                        }
                        if(not vis.contains(hash(a))){
                            vis.insert(hash(a));
                            q.push(a);
                        }
                        a = temp; // reset to intial state
                    }
                }
            }
            flip++;
        }
        return -1;
    }
};