class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> ump;
        int maxi = 0; char c = 0;
        
        for(auto &it: s){
            ump[it]++;
            
            int check = ump[it];
            
            // this condition is the main part
            if(check > (n+1)/2)
                return "";
            
            if(check > maxi){
                maxi = check;
                c = it;
            }
        }
        
        // for(auto [a,b] : ump){
        //     pq.push({b,a});
        // }
        
        string res = s;
//         while(pq.size() >= 2){
//             char a= pq.top().second;
//             int c1= pq.top().first-1;
//             pq.pop();
            
//             char b = pq.top().second;
//             int c2 = pq.top().first-1;
//             pq.pop();
            
//             res += a;
//             res += b;
            
//             if(c1 > 0)
//                 pq.push({c1,a});
            
//             if(c2>0)
//                 pq.push({c2,b});
//         }
        
//         if(pq.size() == 1 && pq.top().first == 1)
//             res += pq.top().second;
        
        // add max in even indices
        int i = 0;
        for(; ump[c]>0; i+=2){
            res[i] = c;
            ump[c]--;
        }
        
        for(auto [a,b] : ump){
            if(b == 0)
                continue;
            
            for(; b>0; i+=2){
                
                if(i>=n)
                    i = 1;
                
                res[i] = a;
                b--;
            }
        }
        
        return res;
    }
};