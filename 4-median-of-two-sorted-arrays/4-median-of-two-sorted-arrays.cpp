class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_size=nums1.size()+nums2.size();
        int n2=nums2.size();
        double median;
        for(int i=0;i<n2;i++)
        {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        
        if(total_size %2!=0)
        {
            int i= (total_size+1)/2;
            median= nums1[i-1];
            return median;
        }
        else
        {
            int i= (total_size)/2;
            
            median=((nums1[i-1]+nums1[i])/2.0);
            return median;
        }
        
        return median;
    }
};