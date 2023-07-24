class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int end = 0, start = 0;
        
        while(end<n){
            int c = 1;
            while(end<n-1 && chars[end] == chars[end+1]){
                c++;
                end++;
            }
            
            chars[start++] = chars[end++];
            string num = to_string(c);
            if(c>1){
                for(auto &it: num){
                    chars[start++] = it;
                }
            }
        }
        
        return start;
    }
};