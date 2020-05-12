// Valid Perfect Square
// Solution
// Given a positive integer num, write a function which returns True if num is a perfect square else False.

// Note: Do not use any built-in library function such as sqrt.

// Example 1:

// Input: 16
// Output: true
// Example 2:

// Input: 14
// Output: false

class Solution {
public:
    // double squareRoot(int n)
    // {
    //     return pow(2, 0.5*log2(n));
    // }

    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        if (num == 0 || num == 1) return true;
        long l = 1;
        long r = num / 2;
        long mid = 0;
        long long midSqr = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            midSqr = mid * mid;
            if (midSqr == num) {
                return true;
            }
            else if (midSqr < num) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return false;
    }
};