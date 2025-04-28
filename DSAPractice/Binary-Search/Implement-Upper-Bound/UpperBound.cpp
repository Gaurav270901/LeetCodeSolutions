#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> arr , int x , int n ){
    int ans = n ; 
    int low = 0 , high = n ; 

    while(low <= high){
        int mid = (low + high) / 2 ; 
        if(x < arr[mid]){
            ans = arr[mid];
            high = mid-1 ; 
        }else{
            low = mid+1 ; 
        }
    }
    return ans ; 
}

int main()
{
    vector<int> arr = {3, 5, 8, 9, 15, 19 , 20};
    int n = 6, x = 9;
    int ind = upperBound(arr, x, n);
    cout << "The upper bound is the index: " << ind << "\n";
    return 0;
}
