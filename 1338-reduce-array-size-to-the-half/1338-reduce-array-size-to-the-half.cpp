class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> v(100001,0);
        
        for(auto i : arr){
            v[i]++;
        }
        
        sort(v.begin(),v.end(),greater<int>());
        
        int ans = 0, temp = 0;
        for(auto i : v){
            ans++;
            temp += i;
            
            if(temp >= n/2) return ans;
        }
        
        return ans;
    }
};