class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missingElement ;
        int n = arr.size()-1;
        int elm = 1 ;
        int i = 0 ;
        while(i <= arr.size()-1){
            if(arr[i]==elm){
                i++;
                elm++;
            }
            else{
                missingElement.push_back(elm);
                elm++;
            }
        }
        if(k <= missingElement.size()) return missingElement[k-1];
        else{
            return arr[n]+(k-missingElement.size());
        }
    }
};