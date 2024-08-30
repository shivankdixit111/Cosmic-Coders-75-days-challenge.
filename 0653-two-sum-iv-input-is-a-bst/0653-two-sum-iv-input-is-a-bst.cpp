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
    TreeNode* largest( TreeNode* root) {
        if(root->right==NULL) return root;
        return largest(root->right);
    }
    TreeNode* smallest( TreeNode* root) {
        if(root->left==NULL) return root;
        return smallest(root->left);
    }
    TreeNode* predecessor( TreeNode* root, TreeNode* right, TreeNode* pd) {
        if(!root) return pd;

        if(root->val < right->val) {
            pd = root;
            return predecessor( root->right, right, pd);
        } else {
            return predecessor( root->left, right, pd);
        }
    }
     TreeNode* successor( TreeNode* root, TreeNode* right, TreeNode* sd) {
        if(!root) return sd;

        if(root->val > right->val) {
            sd = root;
            return successor( root->left, right,sd);
        } else {
            return successor( root->right, right,sd);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> mp;  // tc- O(n)  sc- O(n)
        //   return fun(root,k,mp);

        TreeNode* left = smallest(root);
        TreeNode* right = largest(root);

        while(left!=right) {
            int sum = left->val + right->val;
            if(sum==k) return 1;
            if(sum>k) {
                right = predecessor(root,right,NULL);
            } else {
                left = successor(root,left, NULL);
            }
        }
        return 0;
    }
};