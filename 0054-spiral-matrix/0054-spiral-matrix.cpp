class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowStart = 0 , rowEnd = matrix.size() , colmStart = 0 , colmEnd = matrix[0].size();

        vector<int> ans ; 
          if(matrix.size()==0) return ans ; 

        while(rowStart<rowEnd && colmStart < colmEnd){
            for(int i = colmStart ; i < colmEnd ; i++){
                ans.push_back(matrix[rowStart][i]);
            }
            rowStart++;

            for(int i = rowStart ; i < rowEnd ; i++){
                ans.push_back(matrix[i][colmEnd-1]);
            }
            colmEnd--;

            if(rowStart < rowEnd){
                for(int i = colmEnd-1;i>=colmStart ;i--){
                    ans.push_back(matrix[rowEnd-1][i]);
                }
                rowEnd--;
            }

            if(colmStart < colmEnd){
                for(int i = rowEnd-1 ; i >= rowStart ; i--){
                    ans.push_back(matrix[i][colmStart]);
                }
                colmStart++;
            }
        }
        return ans ; 
    }
};