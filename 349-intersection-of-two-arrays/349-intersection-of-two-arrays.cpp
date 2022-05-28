class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int n1 =nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        vector<int> v;
        while(i<n1 && j<n2)
        {
            if(nums1[i]<nums2[j])
                i++;
            else if(nums1[i]>nums2[j])
                j++;
            else
            {
                if(v.size() == 0 || v[v.size()-1] != nums1[i])
                    v.push_back(nums1[i]);
                i++; j++;
            }
        }
        
        return v;
    }
};