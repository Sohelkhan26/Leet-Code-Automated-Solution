/*
*/
class Solution {
public:
    string makeString(vector<int> &row){
        char one = '1' , zero = '0';
        string ans;
        if(row[0])
            swap(one , zero);
        for(int i : row)
            ans.push_back(i ? one : zero);
        return ans;
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> freq;
        for(auto row : matrix)
            freq[makeString(row)]++;
        int ans = 0;
        for(auto it : freq)
            ans = max(ans , it.second);
        return ans;
    }
};