class Solution {
public:
    int width;
    int dp[1001][1001];
    int solve(int i , int maxH , int remW , vector<vector<int>> &books){
        if(i == books.size())
            return maxH; // made a mistake here. return maxH for current shelf. We don't include a book in the current shelf unless it fits. So maxH is always valid
        if(dp[i][remW] != -1)
            return dp[i][remW];
        int take = INT_MAX , skip = INT_MAX;
        int w = books[i][0] , h = books[i][1];
        if(remW - w >= 0){
            int newH = max(maxH , h);
            int newW = remW - w;
            take = max(newH , solve(i + 1 , newH , newW , books)); // max height of out all the books placed in the current shelf
        }
        skip = maxH + solve(i + 1 , h , width - w , books); // maxH so far + requird height for the subproblem.
        return dp[i][remW] = min(take , skip);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        width = shelfWidth;
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , width , books);
    }
};

/*
Shelf width is given. Height can be anything. Return min height so that every book can be placed.
Note: books are ordered and they are to placed as they are , i.e: without breaking the order.

Two choice?
place in the current shelf if total thickness < width
place a new  shelf

Kind of Like knapsack DP?

*/