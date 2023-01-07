class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    
    int totalGas = 0;
    int currentGas = 0;
    int startingStation = 0;
    
    // Perform a single pass through the gas stations
    for (int i = 0; i < n; i++) {
        totalGas += gas[i] - cost[i];
        currentGas += gas[i] - cost[i];
        
        // If the current gas is negative, start the next journey from the next station
        if (currentGas < 0) {
            startingStation = i + 1;
            currentGas = 0;
        }
    }
    
    // Return the starting station if it is possible to complete the circuit,
    // otherwise return -1
    if (totalGas >= 0) {
        return startingStation;
    } else {
        return -1;
    }
}

};