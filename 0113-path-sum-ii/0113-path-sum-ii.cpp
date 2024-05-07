/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    vector<vector<int>> solve(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> path, int sum)
    {
        if(root == NULL) {
            return ans;
        }

        sum += root -> val;
        path.push_back(root -> val);

        if(root -> left == NULL && root -> right == NULL) {
            if(sum == targetSum) {
               ans.push_back(path);
            }

        }

        
        solve(root -> left, targetSum, ans, path, sum);
        solve(root -> right, targetSum, ans, path, sum);

        return ans;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;
        vector<int> path;

       return solve(root, targetSum, ans, path, 0);
        
    }
};