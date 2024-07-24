
class Solution {
public:
    bool solve(int sum, int n, vector<int>& nums, int ind, vector<vector<int>>& dp) {
        if (sum == 0) return true; // Found a subset with the required sum
        if (ind >= n || sum < 0) return false; // Reached the end or sum went negative
        
        if (dp[ind][sum] != -1) return dp[ind][sum]; // Return cached result if available

        bool notTaken = solve(sum, n, nums, ind + 1, dp);
        bool taken = false;
        if (nums[ind] <= sum)
            taken = solve(sum - nums[ind], n, nums, ind + 1, dp);

        return dp[ind][sum] = taken || notTaken;  
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0); 
        if (totalSum % 2 != 0) return false; 

        int targetSum = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(targetSum + 1, -1)); // DP table to store results

        return solve(targetSum, n, nums, 0, dp);
    }
};




bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k + 1, false);

    prev[0] = true;

    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }

    for (int ind = 1; ind < n; ind++) {
        vector<bool> cur(k + 1, false);

        cur[0] = true;

        for (int target = 1; target <= k; target++) {
            bool notTaken = prev[target];

            bool taken = false;
            if (arr[ind] <= target) {
                taken = prev[target - arr[ind]];
            }

            cur[target] = notTaken || taken;
        }

        prev = cur;
    }

    return prev[k];
}
