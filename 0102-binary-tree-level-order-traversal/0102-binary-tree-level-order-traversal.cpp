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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        if(root==NULL) return {};
        q.push({root,0});

        map<int,vector<int>> mp;

        while(!q.empty()) {
            TreeNode* node=q.front().first;
            int cnt= q.front().second;
            q.pop();
            mp[cnt].push_back(node->val);

            if(node->left !=NULL) q.push({node->left,cnt+1});
            if(node->right !=NULL ) q.push({node->right, cnt+1});
        }
        vector<vector<int>> ans;
        
        for(int i=0;;i++) {
            if(mp[i].size()==0) break;
            ans.push_back(mp[i]);
        }
        return ans;

    }
};