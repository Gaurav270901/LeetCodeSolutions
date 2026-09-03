class Solution {
public:
    bool isGuessValid(vector<vector<int>>& arr , int n, int m , int k,int guess){
        int row = n , col = 0 ;
        int count = 0 ;
        while(row >= 0 && col < m){
            int element = arr[row][col];
            if(element <= guess){
                count+=(row+1);
                col++;
            }
            else 
                row--;
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