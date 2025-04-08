class Solution {
public:

    vector<int> generateRow(int rowNum)
    {
        long long ans =1 ; 
        vector<int> row ;
        row.push_back(1);

        for(int i = 1 ; i < rowNum ; i++)
        {
            ans = ans*(rowNum-i);
            ans = ans / i ;
            row.push_back(ans);
        } 
        return row ; 

    }
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> ans;
        for(int i = 1 ; i <= numRows ; i++)
            ans.push_back(generateRow(i));
        /* 
        if (numRows >= 1)
            ans[0][0] = 1;
        if (numRows >= 2) {
            ans[1][0] = 1;
            ans[1][1] = 1;
        }
        for(int i = 2 ; i < numRows ; i++)
        {
            for(int j = 0 ; j < ans[i].size();j++)
            {
                if(j==0 || j==ans[i].size()-1)
                    ans[i][j]=1;
                else
                {
                    ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
                }
            }
        }
        */

        return ans ; 
    }
};