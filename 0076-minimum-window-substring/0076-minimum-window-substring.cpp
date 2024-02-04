class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())
        return "";
        unordered_map<char,int> mp;
        for(auto itr:t)
        mp[itr]++;
        int start=0,len=INT_MAX,l=0,r=0,c=t.size();
        while(r<s.size()){
            if(mp.find(s[r])!=mp.end()){  
                if(mp[s[r]]>0){
                    c--;
                }
                mp[s[r]]--;
            }
            while(l<s.size() && c==0){
                if(len>r-l+1){
                    len=r-l+1;
                    start=l;
                }
                if(mp.find(s[l])!=mp.end()){
                    mp[s[l]]++;
                    if(mp[s[l]]>0){
                       c++;
                    }
                }
                l++;
            }
            r++;
        }
        return len==INT_MAX?"":s.substr(start,len);
    }
};
