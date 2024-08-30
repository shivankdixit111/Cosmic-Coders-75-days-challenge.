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
    
    bool fun( TreeNode* root, int k, unordered_map<int,int> &mp) {
         if(!root) return false;

         mp[k-(root->val)]++;

         if(mp.count(root->val) and k!=2*(root->val)) return true;
         bool left =  fun( root->left, k, mp);
         bool right = fun( root->right, k ,mp);
         return left or right;
         
    }
    bool findTarget(TreeNode* root, int k) {
          unordered_map<int,int> mp;
          return fun(root,k,mp);
    }
};