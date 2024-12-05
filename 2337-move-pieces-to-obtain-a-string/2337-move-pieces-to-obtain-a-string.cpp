class Solution {
public:
    bool canChange(string start, string target) {
        int i=0,j=0;

        if(start.length() != target.length()) return false;

        for(;i<start.length() && j<target.length();){

            if(start[i] != '_' && target[j] != '_'){
                if(start[i] != target[j]) return false;
                else if(start[i] == 'L' && i < j) return false;
                else if(start[i] == 'R' && i > j) return false;
                else{
                    i++,j++;
                }
            }
            if(start[i] == '_') i++;
            if(target[j] == '_') j++;
        }
        for(;j<target.length();){
            if(target[j] == '_') j++;
            else break;
        }
        for(;i<target.length();){
            if(start[i] == '_') i++;
            else break;
        }
        if( i != start.length() || j != target.length()) return false;
        return true;
    }
};
