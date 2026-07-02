class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> sortedInterval , ans;
        bool flag = false ;
        if(intervals.size() == 0 ){
            ans.push_back(newInterval);
            return ans;
        }

        for(int i = 0 ; i < intervals.size();i++){
            int s1 = intervals[i][0];
            int e1 = intervals[i][1];

            if(newInterval[0] < s1){
                sortedInterval.push_back(newInterval);
                flag = true ;
            }
            sortedInterval.push_back(intervals[i]);
        }
        if(!flag) sortedInterval.push_back(newInterval);

        int s1 = sortedInterval[0][0];
        int e1 = sortedInterval[0][1];

        for(int i =1 ; i < sortedInterval.size() ; i++){
            int s2 = sortedInterval[i][0];
            int e2 = sortedInterval[i][1];

            if(s2 <= e1){
                e1 = max(e1 , e2);
                continue;
            }
            ans.push_back({s1,e1});
            s1 = s2 ;
            e1 = e2 ;
        }
        ans.push_back({s1,e1});
        return ans;
    }
};