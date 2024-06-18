#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0; //Starting from the smallest non-negative integer and working up
        long b = sqrt(c); //Starting from the largest possible non-negative integer and work out way down
        
        //We are using a two-pointer approach!
        
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
