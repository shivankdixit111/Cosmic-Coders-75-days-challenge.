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
        map<int,vector<int>> mp;
        if(root==NULL) return {};
        int cnt=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(q.size()) {
            TreeNode* node = q.front().first;
            int cnt = q.front().second;
            q.pop();

            mp[cnt].push_back(node->val);

            if(node->right) {
                q.push({node->right,cnt+1});
            }
            if(node->left) {
                q.push({node->left,cnt+1});
            }
        }
        vector<vector<int>> ans;
        for(int i=0;;i++) {
            if(mp[i].empty()) break;
            if(i%2==0) {
                reverse(mp[i].begin(),mp[i].end());
            }
            ans.push_back(mp[i]);
        }
        return ans;
    }
};