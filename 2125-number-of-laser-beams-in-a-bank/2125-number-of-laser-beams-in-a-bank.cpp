class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0;
        vector<int> v;
        
        for(auto it : bank){
            int c = count(it.begin(),it.end(),'1');
            
            cout<<prev<<" "<<ans<<endl;
            ans += c*prev;
            
            if(c)
                prev = c;
        }
        
        return ans;
    }
};