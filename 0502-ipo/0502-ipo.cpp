class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> vp;
        
        for(int i = 0; i<profits.size(); i++){
            vp.push_back({capital[i],profits[i]});
        }
        
        sort(vp.begin(),vp.end());
        priority_queue<int> pq;
        
        int ptr = 0, ans = 0;
        for(int i = 0; i<k; i++){
            while(ptr<capital.size() && w >= vp[ptr].first){
                pq.push(vp[ptr].second);
                ptr++;
            }
            
            if(pq.empty())
                break;
            
            w += pq.top();
            pq.pop();
        }
        
        return w;
    }
};