class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size() ;
        int row = n-1 ;
        int col = 0 ; 
        while(row >= 0 && col < m){
            int element = matrix[row][col];
            if(target < element){
                row--;
            }
            else if(target > element){
                col++;
            }
            else 
                return true ;
        }
        return false ;
    }
};