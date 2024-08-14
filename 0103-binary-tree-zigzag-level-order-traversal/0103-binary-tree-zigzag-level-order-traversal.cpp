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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root==NULL) return {};
        int cnt=0;
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> ans;

        bool leftToright= true;

        while(q.size()) {
          
            int size = q.size();

            vector<int> row(size); 
            
            for(int i=0;i<size;i++) {
                TreeNode* node = q.front();
                q.pop();

                int idx = leftToright ? i : size-i-1;

                row[idx] = node->val;

                if(node->left) {
                    q.push(node->left);
                    // cout<<node->left->val<<" ";
                }
                if(node->right) {
                    q.push(node->right);
                    // cout<<node->right->val<<" ";
                } 

            } 

            leftToright = !(leftToright);
            ans.push_back(row);
           
        }
      
       
        return ans;
    }
};