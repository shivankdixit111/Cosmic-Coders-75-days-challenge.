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
    TreeNode* firstElement = NULL;
    TreeNode* secondElement = NULL;
    TreeNode* prevNode = new TreeNode(INT_MIN);
    
    void traverse( TreeNode* root) {
        if(!root) return;

        traverse(root->left); 
 
        if(firstElement==NULL and root->val < prevNode->val) { // cause BST is always in sorted order so prev can never be greater
            firstElement = prevNode;
        }
        if(firstElement!=NULL and root->val < prevNode->val) {
            secondElement = root;
        }
        
        prevNode = root;

        traverse(root->right);
    }
    void recoverTree(TreeNode* root) {
         traverse(root); 
         cout<< firstElement->val <<" "<< secondElement->val <<endl;

         swap(firstElement->val,secondElement->val); 
         
    }
};