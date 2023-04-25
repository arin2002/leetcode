class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> vis;
    SmallestInfiniteSet() {
        vis.resize(5001);
        for(int i = 1; i<=1001; i++){
            pq.push(i);
            vis[i] = 1;
        }
    }
    
    int popSmallest() {
        int n = pq.top();
        vis[n] = 0;
        pq.pop();
        return n;
    }
    
    void addBack(int num) {
        if(!vis[num]){
            vis[num] = 1;
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */