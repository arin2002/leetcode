class BrowserHistory {
public:
    
    stack<string> his,forw;
    
    BrowserHistory(string homepage) {
        his.push(homepage);
    }
    
    void visit(string url) {
        while(!forw.empty()){
            forw.pop();
        }
        his.push(url);
    }
    
    string back(int steps) {
        while(steps-- && his.size() > 1){
            forw.push(his.top());
            his.pop();
        }
        return his.top();
    }
    
    string forward(int steps) {
        for(int i = 1; i<=steps && forw.size(); i++){
            his.push(forw.top());
            forw.pop();
        }
        
        return his.top();
    }
};