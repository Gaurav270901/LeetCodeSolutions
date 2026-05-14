class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int> map ; 
        int high = 0 , low = 0 , n = fruits.size() , ans = INT_MIN;
        while(high < n){
            map[fruits[high]]++;

            while(map.size() > 2){
                map[fruits[low]]--;
                if(map[fruits[low]] == 0){
                    map.erase(fruits[low]);
                }
                low++;
            }

            if(map.size() == 2){
                int len = high - low + 1 ;
                ans = max(len , ans);
            }
            high++;
        }

        return (map.size() < 2) ? n : ans;
    }
};