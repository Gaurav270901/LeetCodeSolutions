class Solution {
public:
//create map for tasks and its frequency
//one more map which will store the next valid position where tasks can be scheduled initially for all task it will be 1 freemap
//store frequecy in map 
//create max-heap with pair<freq,task> (int , char) and push pair created by hashmap in it 
//keep one variable to track the position of current position let say pos=1
//while heap not empty 
//  create vector which store the pair which has been popped from the heap but cannot be placed in scheduler 
//   one more while heap not empty iterate through heap for scheduling task
//      for heap.top and heap.pop 
//          if freeMap[top.second] <= pos
//          check if for that pair frequency is greater than 1 then push that pair with frequency-- in heap again and then update the freemap positin for current tasks
// freemap[top.second]+=interval+1
//          else push that pair in vector and continue 
//outside of inner heap loop . push all the element stored in vector again in heap  and then pos++ 
//at the end we will return pos-1

    struct cmp{
        bool operator()(pair<int,char>& a , pair<int,char>& b){
            return a.first < b.first ;
        }

    };
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq ;
        unordered_map<char,int> freeMap ;

        for(auto task : tasks){
            freq[task]++;
            freeMap[task] = 1;
        }

        priority_queue<pair<int,char> , vector<pair<int,char>>, cmp> pq ;
        for(auto a :freq){
             pair<int,char> p = {a.second , a.first};   
             pq.push(p);     
        }
        int pos = 1 ;
        while(!pq.empty()){
            vector<pair<int,char>> parkedTasks ;
            while(!pq.empty()){
                pair<int,char> currentTask = pq.top();
                pq.pop();

                if(freeMap[currentTask.second] <= pos){
                    currentTask.first--;
                    if(currentTask.first > 0){
                        pq.push(currentTask);
                        freeMap[currentTask.second]= pos+n+1 ;  //current position + gap +1      
                    }
                    break;
                }else
                    parkedTasks.push_back(currentTask);
            }

            for(auto task : parkedTasks){
                pq.push(task);
            }
            pos++;      
        }
        return pos-1 ;
    }
};