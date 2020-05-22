// Count Square Submatrices with All Ones
// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.



// Example 1:

// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation:
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.
// Example 2:

// Input: matrix =
// [
//   [1,0,1],
//   [1,1,0],
//   [1,1,0]
// ]
// Output: 7
// Explanation:
// There are 6 squares of side 1.
// There is 1 square of side 2.
// Total number of squares = 6 + 1 = 7.


// Constraints:

// 1 <= arr.length <= 300
// 1 <= arr[0].length <= 300
// 0 <= arr[i][j] <= 1
//    Hide Hint #1
// Create an additive table that counts the sum of elements of submatrix with the superior corner at (0,0).
//    Hide Hint #2
// Loop over all subsquares in O(n^3) and check if the sum make the whole array to be ones, if it checks then add 1 to the answer.


class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        int count = 0;
        for (int i = 0; i < m; ++i) {
            dp[0][i] = mat[0][i];
            count += dp[0][i];
        }
        for (int i = 1; i < n; i++) {
            dp[i][0] = mat[i][0];
            count += dp[i][0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (mat[i][j] == 1) {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
                }
                count += dp[i][j];
            }
        }
        return count;
    }
};