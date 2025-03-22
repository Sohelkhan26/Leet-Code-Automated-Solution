class Solution {
public: 
    map<pair<int,int> , int> dp;
    int solve(int buy , int i , vector <int> &price){
        if(i == price.size())
            return 0;
        if(dp.find({buy , i}) != dp.end())
            return dp[{buy , i}];
        return dp[{buy , i}] = max(buy == INT_MAX ? 0 : price[i] - buy + solve(price[i] , i + 1 , price) , solve(price[i] , i + 1 , price));
    }
    int maxProfit(vector<int>& prices) {
        return solve(INT_MAX , 0 , prices);
    }
};