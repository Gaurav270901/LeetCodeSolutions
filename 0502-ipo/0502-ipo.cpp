class Solution {
public:

    struct cmp{
        bool operator()(int& a ,int& b){
            return a < b;
        }
    };
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       //we will store the (capital,profit) in array and then sort it 
       //we will use max heap and will add the element until capital is less than equal to w 
       //once we get all elmenet for that capital we will add the topelement from heap to the w as it will be the maximum profitable element

       int n = capital.size();
       vector<pair<int,int>> pairs ;
       priority_queue<int ,vector<int> , cmp> pq ;
       for(int i = 0 ; i < n ; i++){
            pairs.push_back({capital[i],profits[i]});
       }
        sort(pairs.begin(),pairs.end());
        int idx = 0 ;
        while(k--){
            while(idx < n){
                if(pairs[idx].first > w)
                    break;  
                pq.push(pairs[idx].second);
                idx++;        
            }

            if(pq.empty())
                return w ;
            w += pq.top();
            pq.pop();
        }
       return w ;
    }
};