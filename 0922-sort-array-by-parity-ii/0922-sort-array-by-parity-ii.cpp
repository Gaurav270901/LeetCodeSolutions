class Solution {
public:

    bool isEven(int no){
        return (no % 2 )==0 ? true : false ;
    }
    vector<int> sortArrayByParityII(vector<int>& arr) {
        int eptr = 0 , optr = 1 ; 
        while(optr < arr.size() && eptr < arr.size()){
            bool isOddRight = !isEven(arr[optr]);
            bool isEvenRight = isEven(arr[eptr]);
            
            if(isOddRight) optr+=2;
            if(isEvenRight) eptr+=2 ; 

            if(!isOddRight && !isEvenRight){
                swap(arr[eptr] , arr[optr]);
            }
        }
        return arr;
    }
};