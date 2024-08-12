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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st1,st2;
        vector<int> ans;
        if(root==NULL) return {};

        st1.push(root);

        while(st1.size()) {
              TreeNode* node = st1.top();
              st1.pop();

              st2.push(node);
              if(node->left) st1.push(node->left);
              if(node->right) st1.push(node->right);
        }
        while(st2.size()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};