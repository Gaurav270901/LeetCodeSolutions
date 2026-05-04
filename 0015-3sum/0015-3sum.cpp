class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int n = arr.size();
        vector<vector<int>> ans ; 
        for(int i = 0 ; i < n-2 ; i++){
            if(i < n && i != 0 && arr[i] == arr[i-1]){
                continue;
            }
            int low = i+1  , high = n-1 , target = -1*arr[i];
            while(low < high){
                int sum = arr[low]+arr[high];
                if(sum==target){
                    vector<int> triplet ;
                    triplet.push_back(arr[i]);
                    triplet.push_back(arr[low]);
                    triplet.push_back(arr[high]);
                    ans.push_back(triplet);
                    low++;
                    high--;

                    while(low < n && arr[low] == arr[low-1])
                        low++;
                    
                    while(high >= 0 && arr[high] == arr[high+1])
                        high--;
                }
                else if(sum > target){
                    high--;
                }
                else{
                    low++;
                }

            }

        }

        return ans;
    }
};