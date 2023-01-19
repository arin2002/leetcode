class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, count = 0;
        
        // unordered_map for prefix mod
        unordered_map<int,int> ump;
        
        // for i = 0 case
        // mtlb  i = 0 pe 5 ha aur divisble 5 ho
        // par 0 na ho map mai to neglect ho jaygei
        ump[0] = 1;
        
        for(auto it: nums){
            sum += it;
            int mod = sum%k;
            // c,c++ programing languages
            // give negative mods on -ve numbers
            // so we have to make this case
            // maping kar rahe h 
            // isme
            if(mod<0)
                mod += k;
            auto i = ump.find(mod);
            if(i != ump.end()){
                count += (i->second);
            }
            
            ump[mod]++;
        }
        
        return count;
    }
};