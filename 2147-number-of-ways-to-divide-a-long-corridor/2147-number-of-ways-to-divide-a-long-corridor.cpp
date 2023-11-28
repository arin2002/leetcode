class Solution {
public:
    int numberOfWays(string corridor) {
        int ans=1,module=1000000007;
        vector<int> seatIndex;

        for(int index=0;index<corridor.length();index++) {
            if(corridor[index]=='S')
                seatIndex.push_back(index);
        }

        if(seatIndex.size()%2==1 || seatIndex.size()==0)
            return 0;

        for(int index=2;index<seatIndex.size();index+=2) {
            ans=((long long int)ans*(seatIndex[index]-seatIndex[index-1]))%module;
        }

        return ans;

    }
};
