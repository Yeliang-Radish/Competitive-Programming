#include <iostream>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int count = 0;
        int d = 2;
        while (n > 1) {
            while (n % d == 0) {
                count += d;
                n /= d;
            }
            d++;
        }
        return count;
    }
};