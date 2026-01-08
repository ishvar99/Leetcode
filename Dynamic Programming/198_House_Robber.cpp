class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int prev2 = 0;
        int prev1 = 0;

        for (int current_house_money : nums) {
            int current_max = max(prev1, current_house_money + prev2);
            prev2 = prev1;
            prev1 = current_max;
        }

        return prev1;
    }
};
