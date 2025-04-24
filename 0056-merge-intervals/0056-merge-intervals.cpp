class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //first we will sort interval array and then after that we will compare it with adjacent element
        //we will add given interval directly when they are not overlapption and condition for that:
        //condition 1 : if ans array is empty 
        //condition 2 : if start element of current interval is greater that the end element of previous interval

        //if we dont get overlapping interval then we will merge them , as interval array is sorted it is clear that and.back()[0]  < interval[i][0] every time 
        //so for overlapping interval we need to only take care of last index , we will take the last index as maximum from ans.back()[1] , interval[i][1]
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> ans ; 

        for(int i = 0 ; i < intervals.size() ; i++){
            if(ans.size()==0 || intervals[i][0] > ans.back()[1])
                ans.push_back(intervals[i]);
            else {
                //we will update ans array as per maximum from ans and current interval last element
                ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
            }
            
        }
        return ans ;
    }
};