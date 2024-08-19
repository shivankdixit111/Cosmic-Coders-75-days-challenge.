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
  TreeNode* rec(vector<int> &inorder, int inStart,int inEnd, vector<int> &postorder, int postEnd,
    int postStart,unordered_map<int,int> &mp) {
       if( inStart>inEnd or postStart>postEnd ) return NULL;

       TreeNode* root = new TreeNode();
       root->val = postorder[postEnd];
       int inRoot = mp[postorder[postEnd]];
       int numsLeft = inEnd - inRoot;

       root -> right = rec( inorder, inRoot+1, inEnd, postorder, postEnd-1, postEnd-numsLeft,mp);
       root -> left = rec( inorder, inStart, inRoot-1, postorder, postEnd-numsLeft-1, postStart,mp);

       return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(); 
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            mp[inorder[i]] = i;
        } 
        // PostOrder  go to R to L and select the root in inorder and break it to left and right
        // inorder with their seperate postorder 

        return rec(inorder,0,n-1,postorder,n-1,0,mp);
    }
};