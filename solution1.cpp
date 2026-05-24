#include <iostream>
#include <string>

#include "solution1.h"

using namespace std;



string solution1(string input, int x) {

    string res = "", numbers;
    int l = 0;
    bool isDigit = false;
    for (int r = 0; r < input.size(); ++r) {
        if (isDigit && isdigit(input[r])) {
            numbers += input[r];
        } else if (isdigit(input[r]) && !isDigit) { 
            l = r; 
            numbers += input[r]; 
            isDigit = true; 
        } else if (!isdigit(input[r]) && isDigit) { 
            res += numbers.insert(0, abs(x-(r-l)), '0'); 
            isDigit = false; 
            res += input[r]; 
            numbers.clear();
        } else res += input[r];
    }
    if (!numbers.empty()) res += numbers.insert(0, x-(input.size()-l),'0');
    return res;
    
}

