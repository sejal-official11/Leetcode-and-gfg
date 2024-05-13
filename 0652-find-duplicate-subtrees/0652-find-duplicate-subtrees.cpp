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
    string solve(TreeNode* root, unordered_map<string, int>&mp, vector<TreeNode*> &duplicates) {

        if(root == NULL) {
            return "/0";
        }
        string left = solve(root->left, mp, duplicates);
        string right = solve(root->right, mp , duplicates);

        string s = left + "," + right + "," + to_string(root->val);
        if(mp[s] == 1) duplicates.push_back(root);
        mp[s]++;
        return s;

    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        vector<TreeNode*> duplicates;

        solve(root, mp , duplicates);
        return duplicates;


    }
};