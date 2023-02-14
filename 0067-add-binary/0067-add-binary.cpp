class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size()-1;
        
        int carry = 0; string ans = "";
        while(i>=0 || j>=0 || carry != 0){
            int x = 0, y = 0;
            
            if(i>=0 && a[i] == '1')
                x = 1;
            
            if(j>=0 && b[j] == '1')
                y = 1;
            
            ans = to_string((x+y+carry)%2) + ans;
            carry = (x+y+carry)/2;
            
            i--; j--;
        }
        
        return ans;
    }
};