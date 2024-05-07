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
public:
int ans = 0;
void pathSumHelper(TreeNode* root, long long targetSum) {
    if(root == NULL) {
        return;
    }

    if(root -> val == targetSum) {
        ans++;
    }

    pathSumHelper(root -> left, targetSum-root->val);
    pathSumHelper(root->right, targetSum-root->val);
}
    int pathSum(TreeNode* root, long long targetSum) {
        if(root == NULL) return 0;
        if(root) {

            pathSumHelper(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);

        }
        return ans;
                
    }
};