class TimeMap {
public:
    
    unordered_map<string, vector<pair<int, string>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!map.count(key))
            return "";
        int start = 0, end = map[key].size();
        while(start<end){
            int mid = start + (end-start)/2;
            if(map[key][mid].first > timestamp)
                end = mid;
            else
                start = mid + 1;
        }
        
        return (start>0) ? map[key][start-1].second : "";
    }
};