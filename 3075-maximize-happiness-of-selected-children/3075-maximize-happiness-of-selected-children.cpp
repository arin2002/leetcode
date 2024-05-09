class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0, n = happiness.size();
        int cnt = k-1;
        // priority_queue<int> pq(happiness.begin(),happiness.end());
        // sort(happiness.begin(),happiness.end(), greater<int>());
        
        // we need k highest
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto &it: happiness){
            pq.push(it);
            
            if(pq.size()>k)
                pq.pop();
        }
        
        while(!pq.empty()){
            
            cout<<pq.top()-cnt<<" ";
            ans += (long long)max(pq.top()-cnt,0);
            pq.pop();
            cnt--;
        }
        
        return ans;
    }
};