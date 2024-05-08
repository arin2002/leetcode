class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // bayers moyers voting algo
        // n/k = (k-1) at max majorirty elemts
        // proof by example see
        // take 2 variables
        // it based on fact that they cancel each other
        // hence we will get n/k 
        // in this verification must be done
        
        vector<int> ans;
        int count1 = 0, count2 = 0, candidate1 = INT_MAX, candidate2 = INT_MAX;
        int n = nums.size();
        
        for(auto &it: nums){
            if(it == candidate1)
                count1++;
            
            else if(it == candidate2)
                count2++;
            
            else if(count1 == 0){
                candidate1 = it;
                count1 = 1;
            }
            else if(count2 == 0){
                candidate2 = it;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        count1 = 0; count2 = 0;
        for(auto &it: nums){
            if(it == candidate1)
                count1++;
            
            if(it == candidate2)
                count2++;
        }
        
        cout<<candidate2;
        if(count1 > n/3)
            ans.push_back(candidate1);
        
        if(count2 > n/3)
            ans.push_back(candidate2);
        
        
        return ans;
    }
};