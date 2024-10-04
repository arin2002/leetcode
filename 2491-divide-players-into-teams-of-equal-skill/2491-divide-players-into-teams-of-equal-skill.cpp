class Solution {
public:
    long long dividePlayers(vector<int>& v) {

        if(v.size() == 2)
            return v[0]*v[1];

        long long ans = 0;

        sort(v.begin(),v.end());
        int i = 0, j = v.size()-1;

        long long prev = v[i]+v[j];
        ans = v[i]*v[j];
        i++;
        j--;
        while(i<j){
            long long temp = v[i] + v[j];
            cout<<temp<<" "<<prev<<" "<<endl;
            if(temp != prev)
                return -1;
            
            ans = ans + v[i]*v[j];
            i++;
            j--;
        }

        return ans;
    }
};