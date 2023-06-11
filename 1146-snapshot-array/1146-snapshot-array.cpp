class SnapshotArray {
public:
    int snaps = 0;
    vector<vector<pair<int,int>>> vp;
    
    SnapshotArray(int n) {
        vp.resize(n,vector<pair<int,int>>(1,{0,0}));
    }
    
    void set(int index, int val) {
        vp[index].push_back({snaps,val});
        // vector<pair<int,int>> v = vp[index];
//         int n = vp[index].size();
//         int last = vp[index][n-1].first;
        
//         if(last < snaps){
//             vp[index].push_back({snaps,val});
//             return;
//         }
        
//         int l = 0, r = n-1;
//         while(l<=r){
//             int mid = (l+r)/2;
//             // cout<<mid<<" ";
//             int snp = vp[index][mid].first;
//             // int val = v[mid].second;
//             if(snp == snaps){
//                 cout<<1;
//                 vp[index][mid] = {snaps,val}; 
//                 break;
//             }
            
//             else if(snp < snaps){
//                 l = mid+1;
//             }
//             else{
//                 r = mid-1;
//             }
//         }
    }
    
    int snap() {
        snaps++;
        return snaps-1;
    }
    
    int get(int index, int snap_id) {
        // vector<pair<int,int>> v = vp[index];
        int l = 0, r = vp[index].size()-1;
        int ans = -1;
        
        while(l<=r){
            int mid = (l+r)/2;
            int snp = vp[index][mid].first;
            int val = vp[index][mid].second;
                
            if(snp <= snap_id){
                ans = val;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        
        return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */