class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> left(26,-1),right(26,-1);
        for(int i=0;i<s.length();i++){
            if(left[s[i]-'a']!=-1){
                right[s[i]-'a']=i;
            }else{
                left[s[i]-'a']=i;
            }
        }
        int count=0;
        for(int i=0;i<26;i++){
            
            if(left[i]!=-1&&right[i]!=-1){
                vector<bool> check(26,false);
                for(int j=left[i]+1;j<right[i];j++){
                 if(check[s[j]-'a']==false){
                     count++;
                     check[s[j]-'a']=true;
                 }
                }
            }
        }
        return count;
    }
};
