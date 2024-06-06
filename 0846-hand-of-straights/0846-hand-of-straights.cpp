class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
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
            
            if (--it->second == 0)
                mp.erase(it);
            
            for (int i = 0; i < groupSize - 1; i++, ele++) {
                auto nextIt = mp.find(ele + 1);
                
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
