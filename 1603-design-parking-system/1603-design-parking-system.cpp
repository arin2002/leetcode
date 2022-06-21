class ParkingSystem {
public:
    int a,b,c;
    ParkingSystem(int big, int medium, int small) {
        a = big;
        b = medium;
        c = small;
    }
    
    bool addCar(int d) {
        if(d == 1 && a>=1)
        {
            a--;
            return true;
        }
        else if(d==2 && b>=1)
        {
            b--;
            return true;
        }
        else if(d == 3 && c>=1)
        {
            c--;
            return true;
        }
        
        return false;    
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */