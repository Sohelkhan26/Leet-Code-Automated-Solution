class StockSpanner {
public:
    vector<int> p;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int n = p.size() - 1 , cnt = 1;
        while(n >= 0 and p[n] <= price)
            cnt++ , n--;
        p.push_back(price);
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */