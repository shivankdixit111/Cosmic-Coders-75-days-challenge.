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
    int maxi= INT_MIN;
    int findMaxsum(TreeNode* root) {
        if(root==NULL) return 0;
        
        int left = max(0, findMaxsum(root->left));
        int right = max(0, findMaxsum(root->right));

         maxi= max(maxi, left+right+root->val);
        // cout<< left+right+root->val<<endl;
        
        return max(left,right) + root->val ;
    }
    int maxPathSum(TreeNode* root) {
        int dummy = findMaxsum(root);
        return maxi;
    }
};