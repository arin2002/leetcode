class Solution {
public:
    bool parseBoolExpr(string expression) {
        char curr;
        stack<char>st;
        
        for(int i=0;i<expression.size();i++)
        {
           
                
            if(expression[i]=='|'||expression[i]=='&'||expression[i]=='!'||expression[i]=='t'||expression[i]=='f'){
                st.push(expression[i]);
            }
            if(expression[i]==')'){
                 bool tr=false;
            bool fa=false;
                while(!st.empty()&&(st.top()=='t'||st.top()=='f')){
                            char ch=st.top();
                            st.pop();
                            if(ch=='t'){tr=true;}  
                            else{fa=true;}
                        
                }
            bool an;
                char ch=st.top();
                st.pop();
                if(ch=='|'){
                    if(tr==true){an=true;}
                    else an=false;
                }
                else if(ch=='&'){
                    if(fa==true){an=false;}
                    else{an=true;}
                }
                else if(ch=='!'){
                    if(tr==true){an=false;}
                    if(fa==true){an=true;}
                }
                if(an){st.push('t');}
                else st.push('f');
            }
        }
       if(st.top()=='t'){return true;}
       else return false;
    }
};
