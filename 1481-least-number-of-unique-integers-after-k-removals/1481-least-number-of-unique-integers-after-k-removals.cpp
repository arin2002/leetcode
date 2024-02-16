class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> ump;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        priority_queue<int> pq;
        vector<int> v;
        
        for(auto &it: arr){
            ump[it]++;
        }
        
        for(auto &[a,b]: ump){
            pq.push(b);
            
            if(pq.size()>k)
                pq.pop();
        }
        
        int ans = ump.size();
        
        while(!pq.empty()){
            v.push_back(pq.top());
            pq.pop();
        }
        
        for(int i = v.size()-1; i>=0; i--){
            if(k >= v[i]){
                ans--;
                 k -= v[i];
            }
            else{
                break;
            }
        }
        
        return ans;
    }
};