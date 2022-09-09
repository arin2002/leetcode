class Solution {
public:
    
    static bool cmp(vector<int> & a, vector<int> &b){
        
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        sort(properties.begin(),properties.end(),cmp);
        
        int ans = 0, max_def = 0;
        
        
        
        int n = properties.size();
        
        // for(int i = 0; i<n;i++){
        //     for(int j = 0; j<2; j++){
        //         cout<<properties[i][j];
        //     }
        // }
        
        for(int i = n-1; i >= 0; i--){
            if(properties[i][1] < max_def)
                ans++;
            
            max_def = max(max_def,properties[i][1]);
        }
        
        return ans;
    }
};