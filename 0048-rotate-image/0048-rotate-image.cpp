#include<bits/stdc++.h>

class Solution {
public:

    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        //as you can see clearly output matrix is first transpose of current matrix and then reverse of each row 
        //transpose is convers rows into column
        for(int i = 0 ; i < size ; i++){
            for(int j = 0 ; j < i ; j++){
                swap(matrix[i][j] ,matrix[j][i]);
            }
        }
        //reverse each row 
        for(int i = 0 ; i < size ; i++){
            reverse(matrix[i].begin() , matrix[i].end());
        }
    }
};