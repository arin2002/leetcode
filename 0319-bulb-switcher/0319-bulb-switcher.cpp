class Solution {
public:
    int bulbSwitch(int n) {
        // observation here is
        // if the number of factor of a number is prime -> bulb on
        // if even -> off
        // like if lets say for bulb 4 we have factors 1,2,4
        // hence at round 1 it will switch on but phir roud mai off ho jayega 
        // aur 4 wale roud mai apna on uske baad koi way nahi h isko vapis on hone ka
        // this is the observation
        
        // at more observation we see only the square root of no of rounds/bulbs will be
        // switched on
        
        // every number have their factors in pairs exceprt the sqrt
        return sqrt(n);
    }
};