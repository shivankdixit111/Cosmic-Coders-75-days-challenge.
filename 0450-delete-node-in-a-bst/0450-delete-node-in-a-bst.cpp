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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root)
        if(root->val < key) root->right = deleteNode(root->right,key);
        else if(root->val > key) root->left = deleteNode(root->left,key);
        else {
            //case 1   leaf node
            if(!root->left and !root->right)
                return NULL;
            //case 2   if node has one child
            if(!root->left or !root->right) 
                return root->left ? root->left : root->right;
            //case3    if node has two child
            // either choose maximum from left subtree or minimum from right subtree
            // we are chosing left subtree
            TreeNode* temp= root->left;
            while(temp->right!=NULL) temp = temp->right;
            root->val = temp->val; // value assigned
            //but we have to also make this rightmost value of left subtree 0
            root->left = deleteNode(root->left, temp->val);
        }
         return root;
    }
};