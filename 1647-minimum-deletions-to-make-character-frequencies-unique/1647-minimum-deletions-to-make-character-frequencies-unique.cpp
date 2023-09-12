class Solution {
public:
    int minDeletions(string s) {
        // int freq[27] = {0};
        vector<int> freq(26);
        // priority_queue<int,vector<int>,greater<int>> pq;
        priority_queue<int> pq;
        int ans = 0;
        
        for(auto &it: s){
            freq[it-'a']++;
        }
        
        for(auto it: freq){
            if(it > 0)
                pq.push(it);
        }
        
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            // cout<<a<<" "<<b<<endl;
            if(a == b){
                a--;
                ans++;
                if(a > 0)
                    pq.push(a);
            }
            pq.push(b);
        }
        
        return ans;
    }
};