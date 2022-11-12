class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // if both max and min heap are empty, then push num in any one of them
        if(maxHeap.empty() and minHeap.empty())
        {
            maxHeap.push(num);
        }
        // Check where the num will be inserted, minHeap or maxHeap
        else
        {
            if(maxHeap.top() < num)
            {
                minHeap.push(num);
            }
            else
            {
                maxHeap.push(num);
            }
        }
        
        // check if both heaps are balanced or not
        int n = maxHeap.size();
        int m = minHeap.size();
        
        // if both the heaps are not balanced , then balance the heaps
        if(abs(n-m) == 2)
        {
            if(n > m)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        } 
    }
    
    double findMedian() {
       
        int n = maxHeap.size();
        int m = minHeap.size();
       
        
        /*  check if n + m is even, if it is even, then take the top elements of both the heaps
            and then get the median. If n + m is odd, then whichever heap size if high, return its top 
            element.
        */
        
        if((n+m)%2 == 0)
        {
            return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
        }
        else
        {
            if(n > m) return maxHeap.top();
            else return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
