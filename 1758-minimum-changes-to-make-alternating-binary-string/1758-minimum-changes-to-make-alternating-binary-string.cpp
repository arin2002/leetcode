class Solution {
public:
    int minOperations(string s) {
        int v=0;
            int v1=0;
        
        for(int i=0;i<s.size();i++){
                if(i%2==0){
                    if(s[i]!='1'){
                        v++;
                    }
                }
                else{
                    if(s[i]=='1'){
                        v++;
                    }
                }
            }
        
            for(int i=0;i<s.size();i++){
                if(i%2==0){
                    if(s[i]!='0'){
                        v1++;
                    }
                }
                else{
                    if(s[i]!='1'){
                        v1++;
                    }
                }
            }
        
        return min(v,v1);
    }
};
