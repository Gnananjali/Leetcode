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
    bool balanced = true;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        if(abs(leftHeight - rightHeight) > 1){
            balanced = false;
            
        }
        return 1+max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
     dfs(root);
     return balanced;
        
    }
};