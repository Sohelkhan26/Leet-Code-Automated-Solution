class Solution {
public:
    int dp[201][201];
    int calculate(int left , int right){
        if(left >= right)
            return 0;
        if(dp[left][right] != -1)
            return dp[left][right];
        int ans = 1e5;
        for(int i = left ; i <= right ; i++)
            ans = min(ans , i + max(calculate(left , i - 1) , calculate(i + 1 , right)));
        return dp[left][right] = ans;
    }
    int getMoneyAmount(int n) {
        memset(dp , -1 , sizeof(dp));
        return calculate(1 , n);
    }
};

/*
First thought of binary search, But that was not the case.
we can pick up any number i in the range (1,n). Assuming it is a wrong guess(worst-case scenario), we have to minimize the cost of reaching the required number. Now, the required number could be lying either to the right or left of the number picked(i). But to cover the possibility of the worst case number chosen, we need to take the maximum cost out of the cost of reaching the worst number out of the right and left segments of i. Thus, if we pick up i as the pivot, the overall minimum cost for the worst required number will be:

cost(1,n)=i+max(cost(1,i−1),cost(i+1,n))
*/