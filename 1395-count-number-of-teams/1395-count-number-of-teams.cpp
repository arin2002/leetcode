class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0;
        
        for(int i=1; i<rating.size()-1; i++){
            int smallLeft=0;
            int smallRight=0;
            int largeLeft=0;
            int largeRight=0;

            for(int j=0; j<i; j++){
                if(rating[j]<rating[i]){
                    largeLeft++;
                }
                else{
                    smallLeft++;
                }
            }

            for(int j=i+1; j<rating.size(); j++){
                if(rating[j]<rating[i]){
                    largeRight++;
                }
                else{
                    smallRight++;
                }
            }

            ans+=(largeLeft*smallRight) + (smallLeft*largeRight);

        }

        return ans;
    }
};
