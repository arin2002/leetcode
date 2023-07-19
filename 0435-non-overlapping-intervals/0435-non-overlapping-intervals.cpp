bool cmp(vector<int>&a,vector<int>&b)
{
    
    if(a[1]!=b[1])return a[1]<b[1];
    return a[0]>b[0];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    
        sort(intervals.begin(),intervals.end(),cmp);

        int ans=0;
        vector<int> last;
        last=intervals[0];
        
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<last[1])
              ans++;
              else
              last=intervals[i];
        }

   return ans; }
};
