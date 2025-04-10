class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size() , low = 0 , high = n;
        vector <int> ans(n + 1);
        for(int i = 0 ; i < n ; i++)
            ans[i] = s[i] == 'I' ? low++ : high--;
        ans[n] = high;
        return ans;
    }
};

/*
Try to be greedy. answer must be a permutation.
So input will be given such that there exist a answer and these number will be in the ragne [0 , n].
greedily assign smallest number to valley points and greatest numbers to peak points. I -> valley point , D -> peak point.
*/