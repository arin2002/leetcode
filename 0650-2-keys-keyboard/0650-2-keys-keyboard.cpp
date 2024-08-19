class Solution {
public:
    int minSteps(int n) {
        return performOperations(n, 1, 0, -1);   
    }

private:
    int performOperations(int n, int onScreen, int prevCopied, int canDoOperation) {
        if(onScreen == n)
            return 0;

        if(onScreen > n || prevCopied > n)
            return INT_MAX;

        int copyAll = INT_MAX;
        int paste   = INT_MAX;
        
        if(canDoOperation)
            copyAll = performOperations(n, onScreen, onScreen, 0);
            
        if(canDoOperation != -1)
            paste = performOperations(n, onScreen + prevCopied, prevCopied, 1);

        int minOp = min(copyAll, paste);

        return (minOp != INT_MAX) ? 1 + minOp : INT_MAX;
    }
};
