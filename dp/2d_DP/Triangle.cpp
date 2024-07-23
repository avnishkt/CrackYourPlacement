class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
       
        vector<int> LastRow(n);
        vector<int> currentRow(n);
        for (int i = 0; i < n; i++) {
            LastRow[i] = triangle[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = LastRow[j];
                int diagonal = LastRow[j + 1];
                currentRow[j] = triangle[i][j] + min(down, diagonal);
            }
            LastRow = currentRow;
        }
        return LastRow[0];
    }
};


// methhpd _2;
int minimumPathSum(vector<vector<int> > &triangle, int n) {
    // Create a 2D DP (dynamic programming) array to store minimum path sums
    vector<vector<int> > dp(n, vector<int>(n, 0));

    // Initialize the bottom row of dp with the values from the triangle
    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            // Store the minimum of the two possible paths in dp
            dp[i][j] = min(down, diagonal);
        }
    }

    // The top-left cell of dp now contains the minimum path sum
    return dp[0][0];
}

// method -3 m3morization

int minimumPathSumUtil(int i, int j, vector<vector<int> > &triangle, int n,
                       vector<vector<int> > &dp) {
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == n - 1)
        return triangle[i][j];

    int down = triangle[i][j] + minimumPathSumUtil(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + minimumPathSumUtil(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(down, diagonal);
}

int minimumPathSum(vector<vector<int> > &triangle, int n) {
    vector<vector<int> > dp(n, vector<int>(n, -1));
    return minimumPathSumUtil(0, 0, triangle, n, dp);
}
