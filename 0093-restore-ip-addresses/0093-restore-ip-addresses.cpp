class Solution {
public:
    
    // for storing ans
    vector<string> ans;
    // temp array for ips
    vector<string> temp;
    
    void solve(int ind, string &s){
        if(ind == s.size() && temp.size() == 4){
            string ip = temp[0] + '.' + temp[1] + '.' + temp[2] + '.' + temp[3];
            ans.push_back(ip);
            return;
        }
        
        if(ind == s.size())
            return;
        
        string tempStr = "";
        // iterate for all possible ans
        for(int i = ind; i<s.size() && temp.size() < 4; i++){
            tempStr += s[i];
            // comvert to int
            int num = stoi(tempStr);
            
            if(num >= 0 && num <= 255){
                temp.push_back(tempStr);
                solve(i+1,s);
                temp.pop_back();
            }
            
            if(num <= 0 || num>255)
                break;
            
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        solve(0,s);
        return ans;
    }
};