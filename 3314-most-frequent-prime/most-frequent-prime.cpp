class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        vector <int> ans = {INT_MIN , -1}; // {freq , num}
        auto prime = [&](int n){
            for(int i = 2 ; i * i <= n ; i++)
                if(n % i == 0)
                    return false;
            return true;
        };
        unordered_map <int,int> freq;
        function<void(int,int,int,int,int)> dfs = [&](int i , int j , int num , int di , int dj){
            if(min(i , j) < 0 or i >= n or j >= m)
                return;
            num = (num * 10 + mat[i][j]);
            if(num > 10 and prime(num)){
                ++freq[num];
                if(freq[num] > ans[0] or (freq[num] == ans[0] and num > ans[1])){
                    ans[1] = num;
                    ans[0] = freq[num];
                }
            }
            dfs(i + di , j + dj , num , di , dj);
        };   
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++){
                for(int di = -1 ; di <= 1 ; di++){
                    for(int dj = -1 ; dj <= 1 ; dj++){
                        if(di == 0 and dj == 0)
                            continue;
                        dfs(i , j , 0 , di , dj);
                    }
                }
            }
        return ans[1];
    }
};