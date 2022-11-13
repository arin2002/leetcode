class Solution {
public:
    int minimumSum(int num) {
        vector<int> v;
        
        while(num>0){
            v.push_back(num%10);
            num/=10;
        }
        
        sort(v.begin(),v.end());
        
        int i = 0, j = v.size()-1;
        
        int sum1 = v[0]*10 + v[3];
        int sum2 = v[1]*10 + v[2];
        
        cout<<sum1<<" "<<sum2;
        return sum1+sum2;
    }
};