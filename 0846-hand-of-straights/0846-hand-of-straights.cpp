class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int, int> mp;
        
        if (n % groupSize != 0)
            return false;
        
        for (auto &it: hand) {
            mp[it]++;
        }
        
        for (int k = 0; k < n / groupSize; k++) {
            auto it = mp.begin();
            int ele = it->first;
            
            for (int i = 0; i < groupSize; i++, ele++) {
                auto nextIt = mp.find(ele);
                
                if (nextIt == mp.end()) {
                    return false;
                }
                
                if (--nextIt->second == 0)
                    mp.erase(nextIt);
            }
        }
        
        return true;
    }
};
