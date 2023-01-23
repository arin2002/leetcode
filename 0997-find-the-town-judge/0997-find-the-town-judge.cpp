class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
       vector<int> count(n+1);
        
        for(auto it : trust){
            // because isko trust h kisi pe
            count[it[0]] = -1;
            
            // now jispe bhe trust h usko increment maaro
            count[it[1]]++;
        }
        
        
        for(int i = 1; i<=n; i++){
            if(count[i] == -1)
                continue;
            
            // ye judge hoga hamar
            if(count[i] == n-1)
                return i;
        }
        
        return -1;
    }
};