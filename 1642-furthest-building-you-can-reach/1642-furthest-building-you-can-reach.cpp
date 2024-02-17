class Solution {
public:
    int furthestBuilding(vector<int>& ht, int bricks, int ladders) {
        priority_queue<int>pq;
        //priority_queue<int, vector<int>, greater<int>>pq;
        int n = ht.size(), i;
        for(i=0; i<n-1; i++){
            int diff = ht[i+1]- ht[i];
            if(diff > 0){
                bricks -= diff;
                pq.push(diff);

                if(bricks < 0){
                    bricks += pq.top();
                    pq.pop();
                    ladders--;
                }
                if(ladders <0){
                    break;
                }
            }
        }
        return i;
    }
};
