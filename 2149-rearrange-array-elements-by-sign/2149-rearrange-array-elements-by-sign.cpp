class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        vector<pair<int,int>> neg,pos;
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<0){
                neg.push_back({nums[i],i});
            }
            else{
                pos.push_back({nums[i],i});
            }
        }
        
        for(int i = 0; i<pos.size(); i++){
            
            if(i == 0){
                ans.push_back(pos[i].first);
                ans.push_back(neg[i].first);
            }
            else{
                // cout<<neg[i].second<<" "<<pos[i].second<<" "<<neg[i].first<<" "<<pos[i].first<<endl;
                
                if(neg[i].second<pos[i].second && ans.back()>0){
                    ans.push_back(neg[i].first);
                    ans.push_back(pos[i].first);
                }
                else{
                    ans.push_back(pos[i].first);
                    ans.push_back(neg[i].first);
                }
            }
        }
        
        return ans;
    }
};