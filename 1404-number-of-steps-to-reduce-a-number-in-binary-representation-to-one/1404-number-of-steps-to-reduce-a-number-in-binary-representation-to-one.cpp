class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        
        auto add = [&](){
            int i = s.size()-1, carry = 1;
            string ans;
            
            while(carry || i >= 0){
                int a = 0;
                
                if(i>=0)
                    a = s[i]-'0';
                
                int add = (a+carry)%2;
                carry = (a+carry)/2;
                
                cout<<add<<" ";
                ans += (add+'0');
                i--;
            }
            
            reverse(ans.begin(),ans.end());
            return ans;
        };
        
        
        while(s.size() != 1 || s[0] != '1'){
            int n = s.size();
            
            if(s[n-1] == '1'){
                s = add();
            }
            else{
                s.pop_back();
            }
            
            cout<<s<<endl;
            ans++;
        }
        
        return ans;
    }
};