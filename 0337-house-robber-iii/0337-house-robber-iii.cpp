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
    map<pair<TreeNode*,bool>,int> mp;
    int rec(TreeNode* root,bool f) {
        if(!root) return 0;
        if(mp[{root,f}]) return mp[{root,f}];

        int ans = 0;
        if(f) {
            ans = root->val + rec(root->left,false) + rec(root->right,false);
        } else {
            int a1 = rec(root->left,true) + rec(root->right,true);
            int a2 =  rec(root->left,false) + rec(root->right,false);
            int a3 =  rec(root->left,true) + rec(root->right,false);
            int a4 =  rec(root->left,false) + rec(root->right,true); 

            ans = max(a1,max(a2,max(a3,a4)));
        }
        return mp[{root,f}] = ans;
    }
    int rob(TreeNode* root) {
        return max(rec(root,false),rec(root,true));
    }
};