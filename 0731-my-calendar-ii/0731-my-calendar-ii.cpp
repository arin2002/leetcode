class MyCalendarTwo {
public:
     vector<pair<int,int>> booking;
     vector<pair<int,int>> overlap;
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {

        for(auto i:overlap){
            if(max(start,i.first)<min(end,i.second)){
                return false;
            }
        }
        
        for(auto i:booking){
            if(max(start,i.first)<min(end,i.second)){
                overlap.push_back({max(start,i.first),min(end,i.second)});
            }
        }

        
        booking.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
