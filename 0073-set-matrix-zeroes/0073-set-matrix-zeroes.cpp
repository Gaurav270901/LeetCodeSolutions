#include<climits>
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int columnZero =  1 ;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[i].size() ; j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    if(j != 0)
                        matrix[0][j]=0;
                    else 
                        columnZero = 0 ; 
                }
            }
        }

        for(int row = 1 ; row < matrix.size();row++)
        {
            for(int column = 1 ; column<matrix[row].size();column++)
            {
                if(matrix[row][0]==0 || matrix[0][column]==0)
                    matrix[row][column]=0;
            }
        }

        if(matrix[0][0]==0)
        {
            for(int i = 0 ; i < matrix[0].size();i++)
                matrix[0][i]=0;
        }

        if(columnZero == 0)
        {
            for(int i = 0 ; i < matrix.size();i++)
                matrix[i][0]=0;
        }


        
    }
};