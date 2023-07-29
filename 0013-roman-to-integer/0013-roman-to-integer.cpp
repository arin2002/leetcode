class Solution {
public:
    int Convert(char a){
        if(a == 'I') return 1;
        else if(a == 'V') return 5;
        else if(a == 'X') return 10;
        else if(a == 'L') return 50;
        else if(a == 'C') return 100;
        else if(a == 'D') return 500;
        else if(a == 'M') return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int ans = 0, n = s.size();
        
        for(int i = 0; i<n; i++){
            int curr = Convert(s[i]), next = 0;
            
            if(i<n-1) next = Convert(s[i+1]);
            
            if(curr<next){
                ans -= curr;
            }
            else
                ans += curr;
        }
        
        return ans;
    }
};