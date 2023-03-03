class Solution {
public:
    vector<string>ans;
    void solve(string curr,string &s, int i){
        // if end of the string is reached
        if(i==s.length()){
            ans.push_back(curr); // push the current "curr" string to ans
            return;
        }
        
        if(isdigit(s[i])){ // case 1
            curr.push_back(s[i]);
            solve(curr,s,i+1);
        }
        else{ // case 2
            //sub case 1, considering lower case
            // string c1=curr;
            // c1.push_back(tolower(s[i]));
            char c = tolower(s[i]);
            solve(curr+c,s,i+1);
            
            //sub case 2, considering upper case
            c = toupper(s[i]);
            // c2.push_back(toupper(s[i]));
            solve(curr+c,s,i+1);
        }
    }
    
    vector<string> letterCasePermutation(string &S) {
        ans.clear();
        solve("",S,0);
        return ans;
    }
};
