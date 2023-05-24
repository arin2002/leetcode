class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long n = nums1.size(), ans = 0;
        vector<pair<int,int>> vp;
        for(int i = 0; i<n; i++){
            vp.push_back({nums2[i],nums1[i]});
        }
        
        sort(vp.begin(),vp.end(),greater<pair<int,int>>());
        
        for(int i = 0; i<n; i++){
            nums1[i] = vp[i].second;
            nums2[i] = vp[i].first;
        }
        
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        long long sum = 0;
        for(int i = 0; i<k; i++){
            pq.push(nums1[i]);
            sum += (long)nums1[i];
        }
        ans = max(ans,sum*1LL*nums2[k-1]);
        for(int i = k; i<n; i++){
            sum += nums1[i]-pq.top();
            ans = max(ans,sum*1LL*nums2[i]);
            pq.pop();
            pq.push(nums1[i]);
        }
        
        return ans;
    }
};