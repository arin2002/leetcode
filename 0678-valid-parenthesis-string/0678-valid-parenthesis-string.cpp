class Solution {
public:
    bool checkValidString(string s) {
        int count = 0, star = 0, n = s.size(), cnt = 0;
        
        for(auto &it: s){
            if(it == '('){
                count++;
            }
            else if(it == '*'){
                star++;
            }
            else if(it == ')'){
                if(count){
                    count--;
                }
                else if(star){
                    star--;
                    cnt++;
                }
                else
                    return false;
            }
        }
        
        if(count>0){
            int i = 0;
            while(cnt){
                if(s[i] == '*'){
                    s[i] = '.';
                    cnt--;
                }
                i++;
            }
            
            count = 0, star = 0;
            for(int i = n-1; i>=0; i--){
                if(s[i] == ')'){
                    count++;
                }
                else if(s[i] == '*'){
                    star++;
                }
                else if(s[i] == '('){
                    if(count){
                        count--;
                    }
                    else if(star){
                        star--;
                    }
                    else
                        return false;
                }
            }
        }
        
        return true;
    }
};