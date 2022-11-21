class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> ump;
        
        for(auto it : arr)
            ump[it]++;
        
        for(auto it: arr){
            auto i = ump.find(it);
            
            if(i->second == 1 && --k == 0){
                return it;
            }
        }
        
        return "";
    }
};