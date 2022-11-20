class Solution {
public:
    int countTriples(int n) {
        vector<int> v;
        int ans = 0;
        
        for(int i = 1; i<=n; i++)
            v.push_back(i);
        
        for(int i = 0; i<n-2; i++){
            for(int j = i+1; j<n-1;j++){
                for(int k = j+1; k<n; k++){
                    if((v[i]*v[i])+(v[j]*v[j]) == (v[k]*v[k]))
                        ans+=2;
                    // else if((v[i]*v[i])+(v[j]*v[j]) > (v[k]*v[k]))
                    //     break;
                }
            }
        }
        
        return ans;
    }
};