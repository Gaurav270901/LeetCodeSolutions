class Solution {
public:
    bool isGuessValid(vector<vector<int>>& arr , int n, int m , int k,int guess){
        int row = n , col = 0 ;
        int count = 0 ;
        while(row >= 0 && col < m){
            int element = arr[row][col];
            if(element <= guess){
                count+=(row+1); // if any element is found less than equal to guess it means that all element from the same column above it will be less than or equal to guess hence add all of then in ans and then skip the column
                col++;
            }
            else 
                row--; //if first element of row is > guess it means next all element from that row will be greater than guess as rows are in increasing order hence skip the row
        }
        return count >= k;
        
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size() , m = matrix[0].size();
        int low = matrix[0][0] , high = matrix[m-1][n-1];
        int res = -1 ;
        while(low <= high){
            int guess = (low + high)/2 ;
            if(isGuessValid(matrix , n-1 , m , k , guess)){
                res = guess ;
                high = guess-1 ;
            }
            else
                low = guess+1 ;
        }
        return res ;
    }
};