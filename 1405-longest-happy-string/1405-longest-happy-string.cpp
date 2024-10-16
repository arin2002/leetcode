class Solution {
public:
   

    string longestDiverseString(int a, int b, int c) {
    // Max heap to store counts of 'a', 'b', 'c' with the letter
    priority_queue<pair<int, char>> pq;
    
    if (a > 0) pq.push({a, 'a'});
    if (b > 0) pq.push({b, 'b'});
    if (c > 0) pq.push({c, 'c'});
    
    string result = "";
    
    while (!pq.empty()) {
        auto first = pq.top(); pq.pop();
        
        // If the last two characters in the result are the same as the current one, use another character if possible
        if (result.size() >= 2 && result.back() == first.second && result[result.size() - 2] == first.second) {
            if (pq.empty()) break; // No other character to use, so break
            
            // Use the second most frequent character
            auto second = pq.top(); pq.pop();
            result += second.second;
            second.first--;
            
            if (second.first > 0) pq.push(second);
            
            // Push the first one back
            pq.push(first);
        } else {
            // Otherwise, use the most frequent character
            result += first.second;
            first.first--;
            
            if (first.first > 0) pq.push(first);
        }
    }
    
    return result;
}

};
