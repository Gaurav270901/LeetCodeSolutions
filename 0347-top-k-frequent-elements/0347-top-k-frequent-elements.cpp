class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            return a.first > b.first;
        }
    };



    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans ;
        unordered_map<int,int> mp ;
        priority_queue<pair<int,int>,vector<pair<int,int>> ,cmp> heap ;

        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }

        for(auto i : mp){
            int element = i.first;
            int freq = i.second;

            pair<int,int> curr = {freq , element};

            if(heap.size() < k){
                heap.push(curr);
                continue ;
            }

            if(curr.first > heap.top().first){
                heap.pop();
                heap.push(curr);
            }
        }

        while(heap.size() != 0){
            int curr = heap.top().second ; 
            ans.push_back(curr);
            heap.pop();
        }
        return ans ;
    }
};