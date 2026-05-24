#include <string>
#include "solution2.h"

using namespace std;

string solution2(string input, int x) {
    string integers = "", res = "";
    int indexStart = -1, indexEnd = -1;
    
    for (int i = 0; i < input.size(); ++i) {
        if (!isdigit(input[i])) {
            if (indexStart != -1) { integers.insert(0, x - (indexEnd - indexStart + 1), '0'); res += integers; integers = ""; indexStart = -1; indexEnd = -1; }
            res += input[i];
        }
        else { 
            if (indexStart != -1) { integers += input[i]; indexEnd = i; }
            else { indexStart = i; indexEnd = i; integers += input[i]; }
        }
    }
    
    if (indexStart != -1) { integers.insert(0, x - (indexEnd - indexStart + 1), '0'); res += integers; }
    return res;
    
}