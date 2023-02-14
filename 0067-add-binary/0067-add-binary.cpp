class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length(), n2 = b.length();
        int carry = 0; string ans ="";
        int i = n1-1, j = n2 - 1;
        while(i>=0 || j>=0 || carry != 0)
        {
            int x = 0, y =0;
            
            if(i>=0 && a[i] == '1')
                x = 1;
            
            if(j>=0 && b[j] == '1')
                y = 1;
            
            ans = to_string((x+y+carry)%2)+ans;
            carry = (x+y+carry)/2;
            
            i--; j--;
        }
        
        return ans;
    }
};