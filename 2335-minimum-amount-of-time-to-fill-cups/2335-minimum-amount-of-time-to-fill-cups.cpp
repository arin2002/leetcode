class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        
        for(auto it: amount){
            if(it)
                pq.push(it);
        }
        
        int count = 0;
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            if(a != 0)
                a--;
            
            if(b!=0)
                b--;
            
            if(a!=0)
                pq.push(a);
            
            if(b!=0)
                pq.push(b);
            
            count++;
        }
        
        if(pq.empty())
            return count;
        
        count += pq.top();
        return count;
    }
};