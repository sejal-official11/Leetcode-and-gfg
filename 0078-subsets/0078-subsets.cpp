class Solution {
    private:
     void solve(vector<int>& nums, vector<int> subs, vector<vector<int>> &ans, int index) {
        // Base Case
        if(index == nums.size()) {
            ans.push_back(subs);
            return;
        }

        solve(nums, subs, ans, index+1);
        subs.push_back(nums[index]);
        solve(nums, subs, ans, index+1);
     }
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> subs;
        solve(nums, subs, ans, 0);

        return ans;
        
    }
};