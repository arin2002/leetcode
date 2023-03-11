class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> in;
    unordered_map<string,pair<int,int>> total;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string end = in[id].first +"->"+ stationName;
        int total_time = total[end].first + t - in[id].second;
        int count = total[end].second+1;
        
        total[end] = {total_time,count};
        in.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string s = startStation +"->"+ endStation;
        double time = total[s].first;
        double n = total[s].second;
        
        return time/n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */