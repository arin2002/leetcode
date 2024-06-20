class Solution {
public:
bool canweplace(vector<int>& position, int dist ,int m){
    int cntballs =1;
    int coordinates = position[0];
    for(int i = 1 ; i < position.size() ; i++){
        if(position[i] - coordinates >= dist){
            cntballs++;
            coordinates = position[i];
        }
        if(cntballs >= m)return true;
    }
    return false;
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int max = *max_element(position.begin(), position.end());
         int min = *min_element(position.begin(), position.end());
        int s = 1;
        int e = max-min;
        while(s <= e){
            int mid = s+(e-s)/2;
            if(canweplace(position , mid , m)){
                s=mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return e;
    }
};
