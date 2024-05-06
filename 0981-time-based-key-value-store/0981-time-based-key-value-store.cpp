class TimeMap {
public:
    unordered_map<string,map<int,string>> ump;
    
    TimeMap() {
        // unordered_map<string,unordered_map<int,string>> ump;
    }
    
    void set(string key, string value, int timestamp) {
        ump[key][timestamp] =value;
    }
    
    string get(string key, int timestamp) {
            if (ump.find(key) != ump.end()) {  // Check if the key exists
        auto& inner_map = ump[key];    // Get the inner map associated with the key
        auto it = inner_map.upper_bound(timestamp);  // Find the first element greater than timestamp
        if (it != inner_map.begin()) {  // Ensure we don't decrement end() iterator
            --it;  // Decrement to get the largest element less than or equal to timestamp
            return it->second;  // Return the value associated with the found timestamp
        }
    }
    return "";  // Return an empty string if key doesn't exist or no suitable timestamp found

    }
};

/*
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */