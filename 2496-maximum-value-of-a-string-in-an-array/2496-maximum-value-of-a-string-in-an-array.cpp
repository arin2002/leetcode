class Solution {
public:
    int maximumValue(vector<string>& strs) {
        
        int ans = 0;
        for(auto it : strs){
            string temp;
            
            int flag = 0;
            for(auto i : it){
                if(i >= 'a' && i<= 'z'){
                    flag = 1;
                    int s = it.size();
                    ans = max(ans,s);
                    break;
                }
                temp += i;
            }
            
            if(flag == 0){
                int n = stoi(temp);
                ans = max(ans,n);
            }
        }
        
        return ans;
    }
};