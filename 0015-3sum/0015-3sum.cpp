class Solution {
public:
    // vector<vector<int>> threeSum(vector<int>& arr) {
    //     vector<vector<int>> ans ; 
    //     sort(arr.begin() , arr.end());

    //     for(int i = 0 ; i < arr.size() ; i++){
    //         if(i > 0 && arr[i]==arr[i-1]) continue ; 

    //         int left = i+1 ; 
    //         int right = arr.size()-1;

    //         while(left < right){
    //             int sum = arr[i]+arr[left]+arr[right] ; 
    //             if(sum==0){
    //                 ans.push_back({arr[i],arr[left],arr[right]});
                
    //                 while(left < right && arr[left]==arr[left+1]) left++;
    //                 while(left < right && arr[right]==arr[right-1]) right--;

    //                 left++;
    //                 right--;
    //             }
    //             else if(sum < 0) left++ ;
    //             else right --;
    //         }
    //     }
    //     return ans ; 
    // }

     vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> ans ; 
        sort(arr.begin() , arr.end());

        for(int i = 0 ; i < arr.size() ; i++){
            if(i > 0 && arr[i]==arr[i-1]) continue ; 

            int left = i+1 ; 
            int right = arr.size()-1;

            while(left < right){
                int sum = arr[i]+arr[left]+arr[right] ; 
                if(sum > 0) right-- ; 
                else if (sum < 0 ) left++;
                else {
                    ans.push_back({arr[i],arr[left],arr[right]});
                    left++;

                    while(left < right && arr[left]==arr[left-1]) left++;
                }
            
            }
        }
        return ans ; 
    }
};