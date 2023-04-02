class Solution {
public:
    
    int find(long spell, vector<int>& potions, long long success){
        int i = 0, j = potions.size()-1;
        
        int ans = 0;
        while(i<=j){
            long mid = (i+j)/2;
            long long spells = 1LL*spell*potions[mid];
            
            if(spells >= success){
                // ans = j;
                j = mid-1;
            }
            else
                i = mid+1;
        }
        
        // cout<<potions[ans]<<endl;
        
//         if(i == potions.size()-1 || i == potions.size())
//             return 0;
        
        return potions.size()-1-j;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // sort(spells.begin(),spells.end());
        sort(potions.begin(),potions.end());
        vector<int> ans;
        
        for(auto it: spells){
            ans.push_back(find(it,potions,success));
        }
        
        return ans;
    }
};