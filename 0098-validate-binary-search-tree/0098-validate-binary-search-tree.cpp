/**
 * Definition for a binary tree root.
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
    bool isValid( TreeNode* root, long lb, long ub) {
         if(!root) return true;
         
         bool cond1 = (root->val > lb);
         bool cond2 = (root->val < ub);
         bool left = isValid( root->left, lb, root->val); // root->val will be upperbound for 
         // every value of left subtree
         bool right = isValid( root->right, root->val, ub); // every value of right subtree
         // should be greater than root->val

         return ( cond1 and cond2 and left and right);
    }
    bool isValidBST(TreeNode* root) {
         
         long lb = LONG_MIN, ub = LONG_MAX;
         return isValid( root,lb,ub );
    }
};