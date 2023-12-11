class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 1, n = arr.size(), prev = arr[0];
        
        for(int i = 1; i<n; i++){
            if(prev != arr[i]){
                double percen = ((double)count/(double)n)*100;
                
                cout<<prev<<" "<<count<<" "<<percen<<" "<<endl;
                if(percen > 25.0){
                    return prev;
                }
                count = 1;
                prev = arr[i];
            }
            else{
                count++;
            }
        }
        
        return arr[n-1];
    }
};