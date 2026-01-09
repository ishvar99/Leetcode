class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> groups;
        int n = nums.size();
        
        for (int r = n - 1; r >= 0; r--) {
            for (int c = 0; c < nums[r].size(); c++) {
                int sum = r + c;
                if (sum >= groups.size()) {
                    groups.resize(sum + 1);
                }
                groups[sum].push_back(nums[r][c]);
            }
        }
        
        vector<int> result;
        for (const auto& group : groups) {
            for (int val : group) {
                result.push_back(val);
            }
        }
        
        return result;
    }
};
