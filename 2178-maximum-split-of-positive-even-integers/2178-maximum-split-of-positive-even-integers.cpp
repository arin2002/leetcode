class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        
        if(finalSum%2)
            return ans;
        
        int currSum = 0, i = 2;
        
        while((currSum+i) <= finalSum){
            ans.push_back(i);
            finalSum -= i;
            i+=2;
        }
        
        // cout<<ans[ans.size()-1];
        ans[ans.size()-1] += (finalSum-currSum);
        return ans;
    }
};