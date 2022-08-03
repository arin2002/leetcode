class MyCalendar {
    multiset<pair<int,int>>p;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        p.insert(make_pair(start,1));
        p.insert(make_pair(end,-1));
        
        int book=0;
        
        for(auto it:p)
        {
            book+=it.second;
            
            if(book>1)
            {
                p.erase(p.find(make_pair(start,1)));
                p.erase(p.find(make_pair(end,-1)));
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */