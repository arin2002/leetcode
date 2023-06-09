class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = '.';
        for(auto &it: letters){
            if(it>target){
                if(ans == '.' || ans>it){
                    ans = it;
                }
            }
        }
        return ans == '.' ? letters[0]:ans;
    }
};