class Solution {
public:
    
    
    string intToRoman(int A) {

    string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};

    string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};

    string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};

    string thns[] = {"","M","MM","MMM"};

    

    return thns[A/1000] + hrns[(A%1000)/100] + tens[(A%100)/10] + ones[A%10];

}
};
