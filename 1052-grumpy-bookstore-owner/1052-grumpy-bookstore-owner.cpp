class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size(),sum=0;
        vector<int> prefixWithGrumpy(n,0),prefix(n,0);
        for(int i=0;i<n;i++){
            sum+=customers[i];
            prefix[i]=sum;
        }
        sum=0;
        for(int i=0;i<n;i++){
            if(!grumpy[i]){sum+=customers[i];}
            prefixWithGrumpy[i]=sum;
        }
        int temp=prefixWithGrumpy[n-1],ans=0;
        for(int j=minutes-1;j<n;j++){
            int i=j-(minutes-1);
            int remove=prefixWithGrumpy[j],add=prefix[j];
            if(i > 0){
                remove-=prefixWithGrumpy[i-1];
                add-=prefix[i-1];
            }
            int apply=temp-remove+add;
            ans=max(ans,apply);
        }
        return ans;
    }
};
