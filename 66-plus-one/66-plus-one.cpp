class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v;
        int n = digits.size(), carry = 0;
        int i = n-1;
        while(i>=0 || carry!=0)
        {
            int x = 0;
            if(i>=0)
                x = digits[i];
            
            if(i == n-1)
                x = digits[i]+1;

            v.push_back((x+carry)%10);
            carry = (x+carry)/10;
            
            i--;
        }
         reverse(v.begin(),v.end());
        return v;
    }
};