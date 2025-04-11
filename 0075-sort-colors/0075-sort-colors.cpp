class Solution {
public:
    void sortColors(vector<int>& arr) {

        //initialize three pointers 
        //low , mid pointing to first position 
        //high poining to last position
        //iterate array using mid pointer until mid <= high
        //if we get any element equal to 0 we will swap that number with low 
        //if number is one then keep it as it is and increment mid pointer
        //if number is two swap mid with high and decrement high and increament low 
       int n = arr.size() , low = 0 , mid = 0 , high = arr.size()-1;

       while(mid <= high){
        if(arr[mid]==0){
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
       }

    }
};