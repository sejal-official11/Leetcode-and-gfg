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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> ans;
         if(root == NULL) 
         {
            return ans;
         }
        queue<TreeNode*> q;
        
        q.push(root);
        bool level = false;

        while(!q.empty()) {
            int size = q.size();
            vector<int> v(size);
            for(int i = 0; i < size; i++) {
                
                int j = level == false ? i : size-i-1;
                TreeNode* front = q.front();
                q.pop();
                if(front->left) {
                    q.push(front->left);
                }
                if(front->right) {
                    q.push(front->right);
                }
                v[j] = front->val;   
            }

            level = !level;
            ans.push_back(v);

        }

        return ans;

        
    }
};