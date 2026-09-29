class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        if ((m + n - 1) % 2 != 0)
            return false;

        int maxBalance = m + n;

        vector<vector<bool>> dp(n, vector<bool>(maxBalance + 1, false));
        dp[0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                vector<bool> cur(maxBalance + 1, false);

                int change = (grid[i][j] == '(') ? 1 : -1;

                for (int balance = 0; balance <= maxBalance; balance++) {
                    bool possible = false;

                    if (i > 0 && dp[j][balance])
                        possible = true;

                    if (j > 0 && dp[j - 1][balance])
                        possible = true;

                    if (!possible)
                        continue;

                    int newBalance = balance + change;

                    if (newBalance >= 0 && newBalance <= maxBalance)
                        cur[newBalance] = true;
                }

                dp[j] = cur;
            }
        }

        return dp[n - 1][0];
    }
};