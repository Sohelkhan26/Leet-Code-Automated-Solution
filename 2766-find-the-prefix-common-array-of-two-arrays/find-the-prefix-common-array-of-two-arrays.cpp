class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector <int> freq(n + 1) , ans(n);
        for(int i = 0 ; i < n ; i++){
            ans[i] = i > 0 ? ans[i - 1] : 0;
            ans[i] += ++freq[A[i]] == 2;
            ans[i] += ++freq[B[i]] == 2;
        }
        return ans;
    }
};