class Solution {
public:
    
    bool check(vector<int> v, vector<int> a)
    {
        for(int i = 0; i<10; i++){
            if(v[i] != a[i])
                return false;
        }
        
        return true;
    }
    
    vector<int> count(int n)
    {
        vector<int> v(10,0);
        
        while(n>0){
            v[n%10]++;
            n/=10;
        }
        
        return v;
    }
    
    bool reorderedPowerOf2(int n) {
        vector<int> v = count(n);
        
        for(int i = 0 ; i<31; i++){
            vector<int> temp = count(pow(2,i));
            
            if(check(v,temp))
                return true;
        }
        
        return false;
    }
};