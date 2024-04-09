class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int count=0;
        while(t[k]){
            for(int i=0;i<t.size();i++){
                if(t[i]>0){
                    if(t[k]==0) break;
                    t[i]--;
                    count++;
                }
            }
        }
        return count;
    }
};
