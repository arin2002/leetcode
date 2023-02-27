class Solution {
public:
    string sortSentence(string s) {
        string temp;
        
        map<int,string>mp;
        
        int i = 0;
        while(i<s.size()){
            while(i<s.size()){
                if(s[i] >= '1' && s[i] <='9')
                    break;
                
                temp += s[i++];
            }
            
            mp[s[i]-'0'] = temp;
            i+=2;
            temp = "";
        }
        
        string ans;
        for(auto it : mp){
            cout<<it.second<<endl;
            ans += it.second+" ";
        }
        ans.pop_back();
        return ans;
    }
};