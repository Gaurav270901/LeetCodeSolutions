class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        stack<int> nextSt , prevSt ; 
        vector<int> nextSmall(n , n ) ;
        vector<int> prevSmall(n , -1) ;

        for(int i = 0 ; i < n ; i++){
            while(!nextSt.empty() && heights[nextSt.top()] > heights[i]){
                nextSmall[nextSt.top()] = i ;
                nextSt.pop();
            }
            nextSt.push(i);
        }

         for(int i = 0 ; i < n ; i++){
            while(!prevSt.empty() && heights[prevSt.top()] >= heights[i]){
                prevSt.pop();
            }

            if(!prevSt.empty())
                prevSmall[i] = prevSt.top();

            prevSt.push(i);
        }

        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            int width = nextSmall[i] - prevSmall[i] -1 ;
            int area = heights[i]* width ; 
            ans = max(area , ans);
        }

        return ans;
    }
};