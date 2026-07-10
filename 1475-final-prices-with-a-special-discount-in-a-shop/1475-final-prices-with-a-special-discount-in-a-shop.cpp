class Solution {
public:
// as we have to find first right element which is less than or equal to current element 
//its obviout that its question of next smaller element
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans = prices ; 
        stack<int> st   ;
        int n = prices.size();
        for(int i = 0 ; i < n ; i++ ){
            while(!st.empty() && prices[st.top()] >= prices[i]){
                ans[st.top()] =  prices[st.top()] - prices[i] ;
                st.pop();
            }

            st.push(i);
        }
        return ans ;
    }
};