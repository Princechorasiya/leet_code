class StockSpanner {
public:
stack<pair<int,int>> st;//store the index and theelement of hte next prev element 
        int index;
    StockSpanner() {
       index=0;

    }
    
    int next(int price) {
        if(st.empty()){
            st.push({index,price});
            index++;
            return 1;
        }
        else{
            while(!st.empty() && st.top().second <=price){
                st.pop();

            }
            if(st.empty()){
                st.push({index,price});
                index++;
                return index;
            }else{
                auto top =st.top();
                st.push({index,price});
                index++;
                return abs( top.first-index+1);
            }
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */