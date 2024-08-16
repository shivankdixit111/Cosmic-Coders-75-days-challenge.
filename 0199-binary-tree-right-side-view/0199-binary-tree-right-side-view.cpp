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
   
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        queue<TreeNode*> q;
        if(root==NULL) return {};
        q.push(root);
        
        while(q.size()) {
           
            int size = q.size();
            bool take=true;
            for(int i=0;i<size;i++) {
                 TreeNode* node = q.front();
                 q.pop();
                 
                 if(take) {
                    ans.push_back(node->val);
                    take=false;
                 }
                 if(node->right) q.push(node->right);
                 if(node->left) q.push(node->left);
            }
        }

        return ans;
    }
};