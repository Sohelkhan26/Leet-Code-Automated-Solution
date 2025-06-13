class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans = 0;
        int rowRem = n , colRem = n;
        unordered_set <int> rowVis , colVis;
        for(int i = queries.size() - 1 ; i >= 0 ; i--){
            int type = queries[i][0] , idx = queries[i][1] , val = queries[i][2];
            if(type == 0 and not rowVis.contains(idx))
                ans += (val * colRem) , rowRem-- , rowVis.insert(idx);
            if(type == 1 and not colVis.contains(idx))
                ans += (val * rowRem) , colRem-- , colVis.insert(idx);
        }
        return ans;
    }
};

/*
Mind blowing. At first i thought of 2D segment tree. Could have been a prime example of 2D segment tree with range update if we were to find sum after each query and query can be done to any range of indices.
Since the value is overwritten, last query will remain intact and then the second last and so on. 
So, if a query is applied to a row/col index that is not present in the future, that query is permanent.
*/