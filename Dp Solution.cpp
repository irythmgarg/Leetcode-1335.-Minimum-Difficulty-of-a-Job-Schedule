class Solution {
public:
    // Declare a 2D DP array to store the results of subproblems
    int dp[301][301];

    // Recursive function to find the minimum total difficulty
    int hlo(vector<int>& jobDifficulty, int i, int d) {
        int n = jobDifficulty.size();

        // If remaining jobs are less than the number of days left, it's not possible
        if (n - i < d) return 1e9;

        // If only one day is left, take the maximum of the remaining jobs
        if (d == 1) {
            return *max_element(begin(jobDifficulty) + i, end(jobDifficulty));
        }

        // If result is already computed, return it (memoization)
        if (dp[i][d] != -1)
            return dp[i][d];

        int result = INT_MAX;
        int currMax = 0;

        // Try placing the first day's jobs from i to j
        for (int j = i; j < n; j++) {
            // Update the max difficulty of the current day's jobs
            currMax = max(currMax, jobDifficulty[j]);

            // Recursively compute the minimum difficulty for remaining jobs and days
            int next = hlo(jobDifficulty, j + 1, d - 1);

            // Update the minimum result
            result = min(result, currMax + next);
        }

        // Store and return the result
        return dp[i][d] = result;
    }

    // Main function to initiate recursion and return final result
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        // If not enough jobs to fill each day, return -1
        if (jobDifficulty.size() < d) return -1;

        // Initialize DP array with -1 (uncomputed state)
        memset(dp, -1, sizeof(dp));

        // Start recursion from index 0 and full number of days
        return hlo(jobDifficulty, 0, d);
    }
};
