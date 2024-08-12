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
        // POST ORDER using One Stack
        
        stack<pair<TreeNode*,bool>> st;
        if(root==NULL) return {};
        vector<int> postorder;
         st.push({root,false});

         while(st.size()) {
            TreeNode* node= st.top().first; 

            if(st.top().second) {
                postorder.push_back(node->val);
                st.pop();
            } else {
                st.top().second=true;
                if(node->right!=NULL) st.push({node->right,false});
                if(node->left!=NULL) st.push({node->left,false});
            }
         }

        return postorder;
    }
};