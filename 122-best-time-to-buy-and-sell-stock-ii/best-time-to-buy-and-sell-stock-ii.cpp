class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() , i = 0 , ans = 0;
        // while(i < n){
        //     while(i < n and prices[i + 1] <= prices[i])i++;
        //     int buy = prices[i];
        //     while(i < n and prices[i + 1] > prices[i])i++;
        //     int sell = prices[i];
        //     ans += sell - buy;
        // }
/// Same code below:
        for(int i = 0 ; i < n - 1 ; i++)
            if(prices[i + 1] > prices[i])
                ans += prices[i + 1] - prices[i];
        return ans;
    }
};

/*
prices = [3 , 2 , 5 , 100 , 140 , 1 , 9]
It is most profitable to buy at last day (when consecutively decreasing 5,4,2 buy at 2), and sell at last day(when consecutively increasing).
If i buy price[1] = 2 and sell price[4] = 140 , profit = 136
This is maximum profit i can gain. 
You can question that , we can buy and sell in between [1,4] and gain more profit. Here comes the important observation: (5-2)+(100-5)+(140-100)=136
(2-100)+(100-140)=136
No matter whatever the sequence, profit remains same.
So the sum of all increases is equal to final sell - initial buy, no matter how many trades you do. This is because addition is associative and distributive—you are just splitting the gain into parts.
It's because of the telescopic sum property:
(a-b)+(b-c)+(c-d) = a-d
*/