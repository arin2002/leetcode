class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int total = n+m;
        
        // trick for small array
        // small mai isliye kyuki operation min ho aur efficent ho operation
        if(m<n){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        //now for cuts in making we can make at most 
        // on small length apply bs
        // ye partion ha confuse mat hona index se
        int start = 0, end = n;
        
        while(start<=end){
            // kitne elements chaiye ye bata rahe cuts
            int cut1 = start + (end - start)/2;
            int cut2 = total/2-cut1;
            
            // now find l1,l2,r1,r2
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];
            int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];
            
            // check valid cut
            if(l1<=r2 && l2<=r1){
                if(total%2 != 0){
                    return min(r1,r2);
                }
                else{
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
            }
            else if(l1 > r2){
                end = cut1-1;
            }
            else{
                start = cut1+1;
            }
        }
        return 0;
    }
};