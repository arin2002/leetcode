class Solution {
public:
    int numSquares(int n) {
        
        // because only one split is possible in this 1^2 like this
        if(n<=3)
            return n;
        
        // lagranges theorm says that ki any natural no can be represnted
        // as sum of 4 integers n = a2+b2+c2+d2
        
        // Legendre's theorem 3 square
        
        // for checking perfect square
        if(ceil(sqrt(n)) == floor(sqrt(n)))
            return 1;
        
        // 4^a term remove
        while(n%4 == 0)
            n/=4;
        
        // 4^a(8b+7)
        if(n%8 == 7)
            return 4;
        
        for(int i = 1; i*i<=n; i++){
            int b = sqrt(n-i*i);
            
            // 2 partions are created
            if(b*b == (n-i*i))
                return 2;
            
        }
        
        
        return 3;
    }
};