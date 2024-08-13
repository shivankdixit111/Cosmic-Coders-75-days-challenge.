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
    int heightBal( TreeNode* root) {
        if(root==NULL) return 0;
        int left = heightBal(root->left);
        int right = heightBal(root->right);

        if(left==-1 or right==-1) return -1;
        if(abs(left-right)>1) return -1;
        
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(heightBal(root)==-1) return false;
        return true;
    }
};