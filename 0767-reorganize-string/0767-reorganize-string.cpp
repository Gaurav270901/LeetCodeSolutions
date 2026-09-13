class Solution {
public:
    struct cmp{
        bool operator()(pair<int,char>& a , pair<int,char> &b){
            if(a.first != b.first)
                return a.first < b.first ;
            return a.second < b.second ;
        }
    };
    string reorganizeString(string s) {
        string ans = "";
        priority_queue<pair<int,char> , vector<pair<int,char>> , cmp> pq ;
        int pos = 0 ;

        unordered_map<char,int> mp ; 
        for(auto chr : s){
            mp[chr]++;
        }

        for(auto i : mp){
            pair<int,char> p = {i.second , i.first};
            pq.push(p);
        }

        while(!pq.empty()){
            pair<int,char> p = pq.top();
            pq.pop();

            if(pos == 0 || ans[pos-1] != p.second){
                ans+= p.second ;
                pos++;
                p.first--;
                if(p.first > 0)
                    pq.push(p);
            }
            else{
                if(pq.empty()) return "";
                pair<int,char> nextPair = pq.top();
                pq.pop();
                ans+= nextPair.second ;
                pos++;
                nextPair.first--;
                if(nextPair.first > 0)
                    pq.push(nextPair);
                pq.push(p);
            }
        }
        return ans ;
    }
};