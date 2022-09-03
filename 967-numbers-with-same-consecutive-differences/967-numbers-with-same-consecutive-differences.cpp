class Solution {
public:
    
    vector<int> v;
    
    int countd(int n){
        int c = 0;
        
        while(n > 0){
            c++;
            n/=10;
        }
        
        return c;
    }
    
    void f(long long int num, long long int n, long long int k){
        
        if(countd(num) == n){
            v.push_back(num);
            return;
        }
        
        for(int i = 0; i<=9; i++){
            long long t = num %10;
            
            if(abs(t-i) == k){
                int a = num *10 + i;
                f(a,n,k);
            }
        }
    }
    
    
    vector<int> numsSameConsecDiff(int n, int k) {
    
        for(int i = 1; i<=9; i++){
           f(i,n,k);
        }
        
        return v;
    }
};