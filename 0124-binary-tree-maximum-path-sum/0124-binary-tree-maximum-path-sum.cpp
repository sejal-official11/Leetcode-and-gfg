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
    int maxPathSumHelper(TreeNode* root, int &maxPath) {
        if(root == NULL) {
            return 0;
        }

        int leftMaxSum = max(maxPathSumHelper(root->left, maxPath), 0);
        int rightMaxSum = max(maxPathSumHelper(root->right, maxPath), 0);
        int currPathSum = root->val + leftMaxSum + rightMaxSum;
        maxPath = max(maxPath, currPathSum);

        return root->val + max(leftMaxSum, rightMaxSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        maxPathSumHelper(root, maxPath);
        return maxPath;


        
    }
};