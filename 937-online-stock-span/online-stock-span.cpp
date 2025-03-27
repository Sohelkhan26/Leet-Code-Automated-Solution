class StockSpanner {
public:
    stack <pair<int,int>> st; // {value , span}
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(not st.empty() and st.top().first <= price)
            span += st.top().second , st.pop();
        st.push({price , span});
        return span;
    }
};

/*
It's based on the idea:
if a < b and c < a then c < b
span is based on consecutive values that are less than or equal to the current element.
*/