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
    void Inorder(TreeNode* root, vector<TreeNode*> & inorder) {
        // base Case
        if(root == NULL) {
            return;
        }
        Inorder(root->left, inorder);
        inorder.push_back(root);
        Inorder(root->right, inorder);
    }

   TreeNode* balancedBST(vector<TreeNode*> &inorder, int s, int e) {

        if(s > e) return NULL;
        int mid = s + (e-s)/2;

        
         TreeNode* root = inorder[mid];
        root->left = balancedBST(inorder, s, mid-1);
        root->right = balancedBST(inorder, mid+1, e);
       

         return root;

        

   }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL) return root;
        vector<TreeNode*> inorder;
         Inorder(root, inorder);
       
        return balancedBST(inorder, 0, inorder.size()-1);
        
    }
};