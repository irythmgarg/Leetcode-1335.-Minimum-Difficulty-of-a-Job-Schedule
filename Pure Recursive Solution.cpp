class Solution {
public:
    // Recursive function to find the minimum total difficulty
    int hlo(vector<int>& jobDifficulty, int i, int d) {
        int n = jobDifficulty.size();

        // If remaining jobs are less than remaining days, it's not possible
        if (n - i < d) return 1e9;

        // If only one day is left, assign all remaining jobs to that day
        if (d == 1) {
            return *max_element(begin(jobDifficulty) + i, end(jobDifficulty));
        }

        int result = INT_MAX;
        int currMax = 0;

        // Try assigning jobs[i...j] to the current day
        for (int j = i; j <= n - d; j++) {
            currMax = max(currMax, jobDifficulty[j]);  // Track max job difficulty for the day
            // Recursively compute min difficulty for remaining jobs and days
            int next = hlo(jobDifficulty, j + 1, d - 1);
            result = min(result, currMax + next);  // Update the minimum result
        }

        return result;
    }

    // Main function to initiate the recursion
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        // If there are not enough jobs to assign one per day, return -1
        if (n < d) return -1;

        // Start recursion from index 0 with d days remaining
        return hlo(jobDifficulty, 0, d);
    }
};
