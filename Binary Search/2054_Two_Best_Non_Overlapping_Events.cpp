#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());

        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; --i) {
            suffixMax[i] = max(events[i][2], suffixMax[i + 1]);
        }

        int maxVal = 0;
        for (int i = 0; i < n; ++i) {
            int currentVal = events[i][2];
            maxVal = max(maxVal, currentVal);

            int left = i + 1, right = n - 1, nextIdx = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > events[i][1]) {
                    nextIdx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            if (nextIdx != -1) {
                maxVal = max(maxVal, currentVal + suffixMax[nextIdx]);
            }
        }

        return maxVal;
    }
};
