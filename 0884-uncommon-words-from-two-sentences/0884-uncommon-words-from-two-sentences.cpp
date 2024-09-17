class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s= s1+" "+s2;

        unordered_map<string,int>  m;

        char *token = strtok(s.data()," ");

        while(token){

            m[token]++;

            token =strtok(NULL," ");
        }
        vector<string> ans;
        for(auto &[key,value]:m)
        {
            if(value==1)
            ans.push_back(key);
        }
        return ans;
    }
};
