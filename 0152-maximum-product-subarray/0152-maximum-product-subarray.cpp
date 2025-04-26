class Solution {
public:
    int maxProduct(vector<int>& arr) {
        //WE WILL TAKE TWO POINTERS ONE WILL POINT TO START AND OTHER WILL POINT TO END OF ARRAY
        //THEN WE WILL START STORING SUM FROM START TO END AND SUM FROM END TO START 
        //AND WE WILL STORE MAXIMUM SUM IN ANS VARIABLE
        //WHENEVER WE GET 0 IN ARRAY WE WILL RESET THE SUM AS 1 
        //AT THE END WE WILL GET HIGHEST SUM


        int startProd = 1 , endProd = 1 , n = arr.size() , ans = INT_MIN; 
        for(int i = 0 ; i < n ; i++){
            if(startProd==0) startProd = 1 ; 
            if(endProd==0) endProd = 1 ; 

            startProd*= arr[i];
            endProd*=arr[n-i-1];
            ans = max(ans , max(startProd , endProd));

        }

        return ans ; 
    }
};