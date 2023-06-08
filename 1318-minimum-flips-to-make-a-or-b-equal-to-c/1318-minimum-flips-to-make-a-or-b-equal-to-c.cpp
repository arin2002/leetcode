class Solution {
public:
    int minFlips(int a, int b, int c) {
        // this will tell us kaha kaha differnt bits aayi h
        int result1 = (a|b)^c;
        
        // ab ye jrrui to nhi h ki dono diff ho
        // same bit pe 1,1 ha to ans ko +2 karna padhega
        // par isme ye miss ho jayega isliye uske liye and operayion se
        // vo jagye nikal lenge jaha same bits ha
        int result2 = (result1)&(a&b);
        int ans = __builtin_popcount(result1)+ __builtin_popcount(result2);
        
        return ans;
    }
};