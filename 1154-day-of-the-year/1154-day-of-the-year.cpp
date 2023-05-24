class Solution {
public:
    int dayOfYear(string date) {
        int dd = stoi(date.substr(8));
        int yy = stoi(date.substr(0,4));
        int mm = stoi(date.substr(5,2));
        
        // cout<<dd<<" "<<mm<<" "<<yy<<endl;
        
        vector<int> m = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        
        int sum = 0;
        for(int i = 1; i<=12; i++){
            sum += m[i];
            m[i] = sum;
        }
        
        int ans = dd + m[mm-1];
        
        if(mm == 1)
            return ans;
        
        if(mm == 2 && dd <= 29)
            return ans;
        
        if(yy%400 ==0 || (yy%100 != 0 && yy%4 == 0))
            ans++;
        
        return ans;
    }
};