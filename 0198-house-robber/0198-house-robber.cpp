class Solution {
private:
    int rob_Helper(vector<int>& nums, int house_no, vector<int>& dp) {
        // Base case --> when all houses are traversed
        if (house_no >= nums.size()) {
            return 0;
        }

        if (dp[house_no] != -1) {
            return dp[house_no];
        }

        int houseIn = nums[house_no] + rob_Helper(nums, house_no + 2, dp);
        int houseOut = rob_Helper(nums, house_no + 1, dp);

        return dp[house_no] = max(houseIn, houseOut);
    }

public:
    int rob(vector<int>& nums) {
        int house_no = 0;

        vector<int> dp(nums.size() + 1, -1);
        return rob_Helper(nums, house_no, dp);
    }
};