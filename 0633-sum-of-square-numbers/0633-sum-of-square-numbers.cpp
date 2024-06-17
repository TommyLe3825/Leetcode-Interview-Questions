#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        long b = static_cast<long>(sqrt(c));
        
        while (a <= b) {
            long sumOfSquares = a * a + b * b;
            if (sumOfSquares == c) {
                return true;
            } else if (sumOfSquares < c) {
                a++;
            } else {
                b--;
            }
        }
        
        return false;
    }
};
