class Solution {
public:

    bool isEven(int no){
        return (no % 2 )==0 ? true : false ;
    }
    vector<int> sortArrayByParityII(vector<int>& arr) {
        int eptr = 0 , optr = 1 ; 
        int size = arr.size();
        while(optr < size && eptr < size){
            bool isOddRight = !isEven(arr[optr]);
            bool isEvenRight = isEven(arr[eptr]);
            
            if(isOddRight) optr+=2;
            if(isEvenRight) eptr+=2 ; 

            if(!isOddRight && !isEvenRight){
                swap(arr[eptr] , arr[optr]);
                eptr+=2 ; 
                optr+=2;
            }
        }
        return arr;
    }
};