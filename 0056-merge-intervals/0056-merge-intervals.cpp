class Solution {
public:
  static bool sortByStart(vector<int> &first , vector<int> &second){
        return first[0] < second[0] ;
    }

    vector<vector<int>> merge(vector<vector<int>>& intr) {
        vector<vector<int>> result ; 
        sort(intr.begin() , intr.end() , sortByStart);
        int start1 = intr[0][0] , end1 = intr[0][1];
        for(int i = 1 ; i < intr.size() ; i++){
            int start2 = intr[i][0];
            int end2 = intr[i][1];

            if(start2 <= end1){
                end1 = max(end1 , end2);
                continue;
            }

            result.push_back({start1 , end1});
            start1 = start2 ; 
            end1 = end2 ;
        }
        result.push_back({start1 , end1});
        return result;
    }
  
};