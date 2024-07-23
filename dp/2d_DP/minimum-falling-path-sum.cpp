
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();

        if (m == 1 || n == 1) return A[0][0];

        vector<vector<int>> dp(m,vector<int>(n, INT_MAX));
        int ans = INT_MAX;

        for (int i = 0; i < A.size(); ++i) {
            ans = min(ans, minFallingPathSum(A, 0, i, dp));
        }

        return ans;
    }

    int minFallingPathSum(vector<vector<int>>& A, int row, int col,  vector<vector<int>>& dp) {
        int m = A.size();
        int n = A[0].size();

        if (dp[row][col] != INT_MAX) return dp[row][col];

        if (row == m - 1)
            return dp[row][col] = A[row][col];

        int left = INT_MAX, right = INT_MAX;

        if (col > 0)
            left = minFallingPathSum(A, row + 1, col - 1, dp);

        int straight = minFallingPathSum(A, row + 1, col, dp);

        if (col < n - 1)
            right = minFallingPathSum(A, row + 1, col + 1, dp);

        dp[row][col] = min(left, min(straight, right)) + A[row][col];

        return dp[row][col];
    }
};


// ??? MWTHOOD _2
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Initialize the last row of dp with the values from the matrix
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = matrix[n - 1][i];
        }

        // Fill the dp table from bottom to top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) { // Iterate over the entire row
                int left = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
                int right = (j < n - 1) ? dp[i + 1][j + 1] : INT_MAX;
                int straight = dp[i + 1][j];
                dp[i][j] = matrix[i][j] + min(straight, min(left, right));
            }
        }

        // The result is the minimum value in the first row of dp
        int result = INT_MAX;
        for (int j = 0; j < n; j++) {
            result = min(result, dp[0][j]);
        }

        return result;
    }
};
