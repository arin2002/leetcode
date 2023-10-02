class Solution {
public:
    bool winnerOfGame(string &s) {
        int a = 0, b = 0, n = s.size();
        
        for(int i = 1; i < n - 1; i++) {
            if(s[i-1] == 'A' && s[i] == 'A' && s[i+1] == 'A') {
                a++;
            } else if(s[i-1] == 'B' && s[i] == 'B' && s[i+1] == 'B') {
                b++;
            }
        }
        
        cout<<a<<" "<<b<<endl;
        return a>b;
    }
};