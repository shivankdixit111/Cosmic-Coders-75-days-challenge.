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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if(root==NULL) return {};
        st.push(root);
        vector<int> inorder;

        while(true) {
            if(root->left) {
                st.push(root->left);
                root=root->left;
            } else {
                if(st.empty()) break;

                TreeNode* node=st.top();
                inorder.push_back(node->val);
                st.pop();

                if(node->right) {
                    root = node->right;   // L N R
                    st.push(root);
                }

            }
        }
        return inorder;
    }
};