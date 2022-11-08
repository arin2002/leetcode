class Solution {
public:
    string makeGood(string s) {        
        int i = 0;
        while(i<s.length()-1){
            if(!s.length())
                break;
            
            if(abs(s[i]-s[i+1]) == 32){
                s.erase(i,2);
                //cout<<s<<endl;
                i = 0;
            }
            else
                i++;
            cout<<i<<" ";
            cout<<s<<endl;
        }
        
        return s;
    }
};