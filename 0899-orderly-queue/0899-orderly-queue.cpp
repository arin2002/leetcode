class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
       set<string>st;
       st.insert(s);
       if(k==1) 
       {
           string a="";
           for(int i=0;i<s.size();i++)
           {
               a=a+s[i];
               string b="";
               for(int j=i+1;j<s.size();j++)
               {
                   b=b+s[j];
               }
               st.insert(b+a);
           }
           return *(st.begin());
       }
       else
       {
          sort(s.begin(),s.end());
          return s;
       }
    }
};
