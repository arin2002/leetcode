class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        int m = s.size();
        
        for(int i = 0; i<m; i++){
            int x = startPos[0], y = startPos[1];
            
            int count = 0;
            for(int j = i; j<m; j++){
                if(s[j] == 'R'){
                    y+=1;
                }
                else if(s[j] == 'L'){
                    y-=1;
                }
                else if(s[j] == 'U'){
                    x-=1;
                }
                else{
                    x+=1;
                }
                
                if(x<0 || x>=n || y<0 || y>=n)
                    break;
                
                count++;
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};