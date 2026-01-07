#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int minDeletionSize(std::vector<std::string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        std::vector<int> dp(m, 1);
        int maxLen = 1;

        for (int j = 1; j < m; ++j) {
            for (int i = 0; i < j; ++i) {
                bool canKeep = true;
                for (int k = 0; k < n; ++k) {
                    if (strs[k][i] > strs[k][j]) {
                        canKeep = false;
                        break;
                    }
                }
                if (canKeep) {
                    dp[j] = std::max(dp[j], dp[i] + 1);
                }
            }
            maxLen = std::max(maxLen, dp[j]);
        }

        return m - maxLen;
    }
};
