class Solution {
public:

//we need to find the closest point to the origin that is minimum distance 
//steop 2 : we need to find k in form of distance between origin and point 
//step 3 : heap of pairs will be <distance , points> 
//step 4 : we need to find smaller distance hence -> max_heap

    struct cmp{
        bool operator()(const vector<int>&a ,const vector<int>&b){
            long long distA = findDistance(a);
            long long distB = findDistance(b) ;

            //as we need to maintain max heap 
            return distA < distB ;
        }
    };

    static long long findDistance(const vector<int>& a){
        long long x = a[0]*a[0];
        long long y = a[1]*a[1];

        return (x + y) ;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //we will iterate through point and will put them in heap 
        vector<vector<int>> ans ;
        priority_queue<vector<int> , vector<vector<int>> , cmp > heap ;

        for(auto point : points){
            heap.push(point);
            if(heap.size() > k) heap.pop();
        }

        while(!heap.empty()){
            ans.push_back(heap.top());
            heap.pop();
        }
        return ans ;
    }
};