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
    TreeNode* find_max(TreeNode* root) {
        if(root == NULL) return root;
        TreeNode* temp = root;
        while(temp->right) {
            temp = temp->right;

        }
        return temp;
    }
    TreeNode* deleteNode_Helper(TreeNode* root, int key) {
        // if root is not present
        if(!root) return root;

        if(root->val == key) {

            // 4 cases are here

            //1. 
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            else if(root->left != NULL && root->right == NULL) {
                TreeNode* temp = root->left;
                 delete root;
                return temp;
            }

            else if(root->left == NULL && root->right != NULL) {
                TreeNode* temp = root->right;
                 root = NULL;
                return temp;
            }
            // the most imp case
           else {
                TreeNode* temp = find_max(root->left);
                root->val = temp->val;
                root->left = deleteNode_Helper(root->left, temp->val);
                return root;
            }
        }
        else{
           if(key > root->val) {
            root->right = deleteNode_Helper(root->right, key); 
           }

           if(key < root->val) {
            root->left = deleteNode_Helper(root->left, key);
           }
        }

        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteNode_Helper(root, key);
        
    }
};