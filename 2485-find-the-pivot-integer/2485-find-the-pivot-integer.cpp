class Solution {
public:
    
    bool solve(vector<int> &v, int ind){
        int i = 0, j = ind+1,sum1 = 0, sum2 = 0;
        
        for(; i<ind; i++){
            sum1+=v[i];
        }
        
        for(; j<v.size(); j++)
            sum2 += v[j];
        
        return sum1 == sum2;
    }
    
    int pivotInteger(int n) {
        vector<int> v;
        
        if(n == 1)
            return 1;
        
        for(int i = 1; i<=n; i++){
            v.push_back(i);
        }
        
        for(int i = 1; i<n; i++){
            if(solve(v,i))
                return v[i];
        }
        
        
        return -1;
    }
};