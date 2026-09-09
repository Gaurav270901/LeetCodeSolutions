class Solution {
public:

   struct cmp {
    bool operator()(const pair<int,string>& a,
                 const pair<int,string>& b) const {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
         int n = words.size();
        vector<string> ans ;
        unordered_map<string,int> mp ;
        priority_queue<pair<int,string>,vector<pair<int,string>> ,cmp> heap ;

        for(auto word : words){
            mp[word]++;
        }

        for(auto i : mp){
            string element = i.first;
            int freq = i.second;

            pair<int,string> curr = {freq , element};
            heap.push(curr);


           if (heap.size() > k) {
                heap.pop();
            }
        }

        while(heap.size() != 0){
            string curr = heap.top().second ; 
            ans.push_back(curr);
            heap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans ;
    }
};