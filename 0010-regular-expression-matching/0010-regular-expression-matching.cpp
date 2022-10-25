class Solution {
public:
    bool f(int i,int j,string &s,string &p)
    { 
        if(i<0 && j<0) return true;   //Both Strings Exhausted
        if(j<0 && i>=0) return false;  //p exhausted but s is remaining
        if(i<0 && j>=0)  //if s is exhausted by p remains , it will only be true if all charcter in p have *;
        {
            while(j>=0)
            {
                if(p[j]=='*') j-=2;
                else return false;
            }
            return true;
        }
        
        if(p[j]==s[i] || p[j]=='.') return f(i-1,j-1,s,p);
        
        if(p[j]=='*')
        {
            if(p[j-1]!=s[i] && p[j-1]!='.')
                return f(i,j-2,s,p);  //Consider * to be empty
            else
            {
                return f(i,j-2,s,p) || f(i-1,j,s,p); 
                //These three case are as follows
                //consider * empty
                //consider * length>=1
            }
        }
        return false;
    }
    
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        return f(n-1,m-1,s,p);
    }
};
