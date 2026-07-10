class StockSpanner {
public:
   stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        pair<int,int> newPrice = {price , 1}; 
        
        while(!st.empty() && st.top().first <= price){
            newPrice.second += st.top().second ;
            st.pop();
        }
        st.push(newPrice);
        return newPrice.second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */