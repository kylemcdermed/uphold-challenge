#include <string>
#include <deque>
#include "solution3.h"

using namespace std;

string solution3(string input, int x) {
    deque<int> d, res;

    for (int i = 0; i < input.size(); ++i) {
        if (isdigit(input[i])) {
            while (!d.empty() && !isdigit(d.back())) { res.push_back(d.front()); d.pop_front(); }
            d.push_back(input[i]);
        } else {
            if (!d.empty() && isdigit(d.back())) {
                res.insert(res.end(), x - d.size(), '0');
                while (!d.empty()) { res.push_back(d.front()); d.pop_front(); }
            }
            d.push_back(input[i]);
        }
    }

    if (!d.empty()) {
        res.insert(res.end(), x - d.size(), '0');
        while (!d.empty()) { res.push_back(d.front()); d.pop_front(); }
    }

    string ans;
    while (!res.empty()) { ans += res.front(); res.pop_front(); }
    return ans;
}