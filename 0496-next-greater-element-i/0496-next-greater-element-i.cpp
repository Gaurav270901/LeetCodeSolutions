class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // first store the values of nums1 in index as val -> index
        // iterate through nums2 
        //check for element if present in map then add it in stack until we find its greater element 
        //those who are not present in map , for them no need to find greater element

        map<int, int> mp ; 
        int n = nums1.size() , m = nums2.size();
        stack<int> st ;
        vector<int> ans (n , -1);
        for(int i = 0 ; i < n ; i++ ){
            mp[nums1[i]] = i ;
        }

        for(int i = 0 ; i < m ; i++){
            while(!st.empty() && nums2[st.top()] < nums2[i]){
                ans[mp[nums2[st.top()]]] = nums2[i];
                st.pop();
            }

            if(mp.find(nums2[i]) != mp.end())
                st.push(i);
        }
        return ans;
    }
};