class LRUCache {
public:
    list<int> dll; // Doubly linked list to keep track of the order of keys (from most recently used to least recently used).
    int n; // Capacity of the LRUCache.
    // unordered_map to store the key-value pair along with its position in the list.
    // The value is a pair containing the iterator to the corresponding node in the list and the value associated with the key.
    unordered_map<int, pair<list<int>::iterator, int>> ump;

    LRUCache(int capacity) {
        n = capacity;
    }

    int get(int key) {
        // Check if the key is present in the LRUCache.
        if (ump.find(key) == ump.end())
            return -1; // Key not found, return -1.

        // Key found, we need to move it to the front (most recently used) and update its position.
        auto it = ump[key].first; // Get the iterator to the node corresponding to the key in the list.
        int ans = ump[key].second; // Get the value associated with the key.

        // Remove the node from the list (as it will be moved to the front).
        dll.erase(it);
        // Add the key to the front of the list (making it most recently used).
        dll.push_front(key);
        // Update the iterator of the key in the unordered_map to point to the new position in the list.
        ump[key].first = dll.begin();

        return ans; // Return the value associated with the key.
    }

    void put(int key, int value) {
        // Check if the key is already present in the LRUCache.
        if (ump.find(key) != ump.end()) {
            // Key exists, update its value and move it to the front (most recently used).
            ump[key].second = value; // Update the value associated with the key.

            // Remove the node from the list (as it will be moved to the front).
            dll.erase(ump[key].first);
            // Add the key to the front of the list (making it most recently used).
            dll.push_front(key);
            // Update the iterator of the key in the unordered_map to point to the new position in the list.
            ump[key].first = dll.begin();

            return; // We're done here.
        }

        // Key doesn't exist, we need to add a new key-value pair to the LRUCache.
        if (dll.size() < n) {
            // LRUCache has not reached its capacity, add the new key-value pair to the front of the list.
            dll.push_front(key);
            // Update the unordered_map with the iterator to the new node in the list and the corresponding value.
            ump[key] = {dll.begin(), value};
        } else {
            // LRUCache is at its capacity, need to remove the least recently used element.

            // Get the key of the least recently used element from the back of the list.
            int lruKey = dll.back();
            // Remove the least recently used element from the list.
            dll.pop_back();
            // Remove the least recently used element from the unordered_map as well.
            ump.erase(lruKey);

            // Add the new key-value pair to the front of the list.
            dll.push_front(key);
            // Update the unordered_map with the iterator to the new node in the list and the corresponding value.
            ump[key] = {dll.begin(), value};
        }
    }
};
