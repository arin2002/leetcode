class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,d;
        int n = senate.size();
        for(int i = 0; i<senate.size(); i++){
            if(senate[i] == 'D')
                d.push(i);
            else
                r.push(i);
        }
        
        while(!r.empty() && !d.empty()){
            int rInd = r.front();
            int dInd = d.front();
            r.pop(); d.pop();
            
            // greedy approach h ki just next d ko apane
            // ko remove karna ha
            if(rInd<dInd){
                // cyclic bana rahe h isliye
                r.push(n+rInd);
            }
            else{
                d.push(n+dInd);
            }
        }
        
        if(d.empty())
            return "Radiant";
        
        return "Dire";
    }
};