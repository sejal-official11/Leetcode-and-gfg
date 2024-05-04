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
int height(TreeNode* root, bool &isbalanced) {
    // Base Case
    if(root == NULL) return 0;

    int lh = height(root -> left, isbalanced);
    int rh = height(root -> right, isbalanced);
    int diff = abs(lh - rh);
    if(isbalanced && diff > 1) {
        isbalanced = false;
    }
    return max(lh, rh) + 1;
}
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        bool isbalanced = true;

        height(root, isbalanced); 
        return isbalanced;


    }
};