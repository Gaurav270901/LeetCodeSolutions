class Solution {
public:
//what we need to find k closed element from x 
//can be solved by heap as need to find k 
//whats the thing we need to find distance between x and element 
//what type of heap as we need to find closest distance heap should be max heap
//what to store in heap  pair of element and its distance <dist , pair > and then using this data to create cmp 

    struct cmp{
        bool operator()(pair<int,int>& a , pair<int,int>& b){
            if(a.first != b.first)
                return a.first < b.first ; // we need to keep larger value on top hence if a < b then b will be on top and can be removed later on 
            return a.second < b.second ; //here also if distance are equal then we want larger value on top hence we will do a.second < b.second so that if b is greater it will be on top and hence removed
        }
    };

  
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans ;
        priority_queue<pair<int,int>, vector<pair<int,int>> , cmp> heap ;

        for(auto element : arr){
            int dist = abs(x-element);
            pair<int,int> curr = {dist , element};
            heap.push(curr);

            if(heap.size() > k)
                heap.pop();
        }

        while(!heap.empty()){
            ans.push_back(heap.top().second);
            heap.pop();
        }
        sort(ans.begin() , ans.end());
        return ans ;
    }
};