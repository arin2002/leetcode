class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        unordered_map<int,int>mp;
        set<int>left,right;
        for(int i=0;i<positions.size();i++){
            if(directions[i]=='L'){
                left.insert(positions[i]);
            }
            else{
                right.insert(-positions[i]);
            }
            mp[positions[i]]=healths[i];
        }
        while((!left.empty()) && (!right.empty())){
            int maxR=-(*right.begin());
            auto validL=left.lower_bound(maxR);
            if(validL==left.end()){
                right.erase(-maxR);
            }
            else{
                int hR=mp[maxR];
                int hL=mp[*validL];
                if(hR==hL){
                    mp[*validL]=0;
                    mp[maxR]=0;
                    left.erase(validL);
                    right.erase(-maxR);
                    
                }
                else if(hR<hL){
                    mp[maxR]=0;
                    mp[*validL]--;
                    right.erase(-maxR);
                    
                }
                else{
                    mp[maxR]--;
                    mp[*validL]=0;
                    left.erase(validL);
                }
            }
            
        }
        vector<int>ans;
        for(int i=0;i<positions.size();i++){
            if(mp[positions[i]]!=0){
                ans.push_back(mp[positions[i]]);
            }
        }
        return ans;
    }
};
