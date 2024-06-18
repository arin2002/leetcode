class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> vec;
        for(int i=0;i<difficulty.size();i++){
            vec.push_back({profit[i],difficulty[i]});
        }
        sort(vec.begin(),vec.end());
        int j=vec.size()-1;
        int ans=0;
        int i=worker.size()-1;
        sort(worker.begin(),worker.end());
        while(j>=0 && i>=0){
            
            while(j>=0 && vec[j].second>worker[i]){
                j--;
            }
            if(j<0)
                break;
            ans+=vec[j].first;
            cout<<ans<<endl;
            i--;
        }
        return ans;
    }
};
