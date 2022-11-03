class Solution {
public:
    string rev (string &s){
        string t = "";
        t +=s[1];
        t +=s[0];
        
        return t;
    }
    
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        int ans = 0;        
        unordered_map<string,int> ump;
        for(auto it : words)
            ump[it]++;
        
        int flag = 1;
        for(auto it : words){
            string s = it;
            reverse(s.begin(),s.end());
            
            auto i = ump.find(s);
            if(it[0] == it[1]){
                if(i->second > 1){
                    ans+=4;
                    ump[it]--;
                    ump[it]--;
                }
                else if(flag && ump[it]>0){
                    cout<<"hi";
                    ans+=2;
                    flag = 0;
                }
                else
                    continue;
            }
            else if(i != ump.end() && i->second>0 && ump[it]>0){
                ans +=4;
                cout<<i->first<<" ";
                cout<<ans<<" ";
                ump[it]--;
                ump[s]--;
            }
        }
        
        return ans;
    }
};