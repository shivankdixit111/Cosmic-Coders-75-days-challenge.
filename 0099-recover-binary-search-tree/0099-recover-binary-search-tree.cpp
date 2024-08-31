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
    void fun(TreeNode* root, TreeNode* lowerbound, TreeNode* upperbound) {
         if(!root) return;
         
         if(root->val < lowerbound->val) {
             swap(root->val , lowerbound->val); 
         }
         if(root->val > upperbound->val) {
             swap(root->val, upperbound->val); 
         }
         fun(root->left , lowerbound, root); // root works as a upperbound for left
         fun(root->right, root, upperbound); // root works as a lowerbound for right
    }
    void recoverTree(TreeNode* root) {
         TreeNode* upperbound = new TreeNode(INT_MAX);
         TreeNode* lowerbound = new TreeNode(INT_MIN);

        for(int i=0;i<10;i++)
         fun(root,lowerbound,upperbound);
          
    }
};