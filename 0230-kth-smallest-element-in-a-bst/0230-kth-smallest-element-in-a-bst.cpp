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
    void rec(TreeNode* root, int k, int &cnt, int &ksm) { 
         if(cnt>k or !root) return;
  
            
            rec( root->left, k, cnt, ksm);

         cnt++;
         if( cnt == k) {
            ksm = root->val;
            return;
         } 

            rec( root->right, k, cnt, ksm);

    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int ksm = -1;
        rec(root,k,cnt,ksm); 
        return ksm;
    }
};