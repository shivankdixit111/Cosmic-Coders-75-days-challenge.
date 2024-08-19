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
    vector<int> preorderTraversal(TreeNode* root) {
               vector<int> preorder;
         // MORRIS preorder  O(1) space complexity
         while(root!=NULL) {
            if(root->left==NULL) {
                 preorder.push_back(root->val);
                 root = root->right;
            } else {
                TreeNode* prev = root->left; 
                // make a thread by going(prev copy goes) to left of root till the rightmost 
                // node of left of root node
                // and delete the thread while returning from it
                while(prev->right and prev->right!=root) {
                    prev = prev->right;
                }
                if(prev->right==NULL) {
                    prev->right = root; // thread connected
                    preorder.push_back(root->val);
                    root = root->left; //explore further left portion
                } else {
                    prev->right = NULL; // delete the thread as everything is explored to that node 
                    // now explore the right portion
                    root= root->right;
                }
            }
         }
         return preorder;
    }
};