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
    TreeNode* prevNode = NULL;

    // void traverse( TreeNode* root) {
    //     if(!root) return;

    //     traverse(root->left); 
 
    //     if(firstElement==NULL and root->val < prevNode->val) { // cause BST is always in sorted order so prev can never be greater
    //         firstElement = prevNode;
    //     }
    //     if(firstElement!=NULL and root->val < prevNode->val) {
    //         secondElement = root;
    //     }
        
    //     prevNode = root;

    //     traverse(root->right);
    // }
    void recoverTree(TreeNode* root) {

        //  traverse(root); 
        //  cout<< firstElement->val <<" "<< secondElement->val <<endl;
        //  swap(firstElement->val,secondElement->val);

        // Follow Up -> O(1) space using Morris Inorder Traversal

        while(root) {
            if(prevNode!=NULL and prevNode->val > root->val) {  
                if(firstElement==NULL) firstElement = prevNode;
                if(firstElement!=NULL) secondElement = root;
            }
            if(root->left==NULL) {
                // take value
                prevNode = root;
                root= root->right;  
            } else {
                //creat thread by going to rightmost node of left subtree 
                // delete after taking value
                TreeNode* prev = root->left;
                while(prev->right!=NULL and prev->right!=root) prev=prev->right;

                if(prev->right==NULL) {
                    // creat thread to root for convience to go to root while returning
                    // as we are using no recursion
                    prev->right = root;
                    //explore left part
                    root= root->left;
                } else {
                    //there is a thread delete it
                    prev->right = NULL;
                    // take value  
                    prevNode = root;
                    root = root->right;
                }
            }
        }

        swap( firstElement->val , secondElement->val );

         
    }
};