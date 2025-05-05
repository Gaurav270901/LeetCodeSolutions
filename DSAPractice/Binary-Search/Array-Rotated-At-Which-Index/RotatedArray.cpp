#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> arr){
    int low = 0 ; 
    int high = arr.size()-1 ;
    int ans = INT_MAX;
    int minIndex = -1 ;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[low]<=arr[mid]){
            if(ans > arr[low]){
                ans = arr[low];
                minIndex = low ; 
            }
            low = mid+1 ;
        }
        else{
            if(ans > arr[mid]){
                ans = arr[mid];
                minIndex = mid ; 
            }            
            high = mid-1 ;
        }
    }
    return minIndex ;
    
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
}