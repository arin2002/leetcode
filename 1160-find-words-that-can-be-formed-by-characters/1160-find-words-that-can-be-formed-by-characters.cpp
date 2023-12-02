class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> ump;
        int ans = 0;
         
        for(auto &it: chars){
            ump[it]++;
        }
        
        for(auto &word: words){
            int flag = 1, n = word.size();
            unordered_map<char,int> u = ump;
            
            for(int i = 0; i<n; i++){
                if(!u[word[i]]){
                    flag = 0;
                    break;
                }
                u[word[i]]--;
            }
            
            if(flag){
                ans += n;
            }
        }
        
        return ans;
    }
};