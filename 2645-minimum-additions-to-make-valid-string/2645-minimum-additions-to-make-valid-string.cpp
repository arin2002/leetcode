class Solution {
public:
    int addMinimum(string s) {
        int n = s.size(), ans = 0;
        int i = 0;
        
        while(i<n){
            string complete = s.substr(i,3);
            string par = s.substr(i,2);
            
            if(complete == "abc"){
                i+=3;
            }
            else if(par == "ab" || par == "ac" || par == "bc"){
                ans += 1;
                i+=2;
            }
            else{
                i++;
                ans += 2;
            }
        }
        return ans;
    }
};