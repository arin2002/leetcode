class Solution {
public:

    // returns the number of ranges that start/end before or equal to the given time (target)
    int binarySearch(vector<vector<int> > &vec,int target){
        int l=0,r=vec.size()-1;
        while(r-l>3){
            int mid=(l+r)/2;
            if(vec[mid][0]>target)r=mid;
            else l=mid;
        }
        for(int i=r;i>=l;i--){
            if(vec[i][0]<=target)return i+1;
        }
        return 0;
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& vec1, vector<int>& people) {
        vector<vector<int> > vec2;
        vector<int> ans;

        for(auto x: vec1)vec2.push_back({x[1],x[0]}); 
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());
        for(auto time: people)ans.push_back(binarySearch(vec1,time)-binarySearch(vec2,time-1));
        return ans;
    }
};
