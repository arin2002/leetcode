class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> ump;
        
        for(auto &it: s){
            ump[it]++;
            
            int check = ump[it];
            
            // this condition is the main part
            if(check > (n+1)/2)
                return "";
        }
        
        for(auto [a,b] : ump){
            pq.push({b,a});
        }
        
        string res;
        while(pq.size() >= 2){
            char a= pq.top().second;
            int c1= pq.top().first-1;
            pq.pop();
            
            char b = pq.top().second;
            int c2 = pq.top().first-1;
            pq.pop();
            
            res += a;
            res += b;
            
            if(c1 > 0)
                pq.push({c1,a});
            
            if(c2>0)
                pq.push({c2,b});
        }
        
        if(pq.size() == 1 && pq.top().first == 1)
            res += pq.top().second;
        
        return res;
    }
};