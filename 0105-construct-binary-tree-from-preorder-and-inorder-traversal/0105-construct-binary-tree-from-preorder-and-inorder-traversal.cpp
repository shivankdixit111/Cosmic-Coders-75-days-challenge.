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
    TreeNode* rec(vector<int> &inorder, int inStart,int inEnd, vector<int> &preorder, int preStart,
    int preEnd,unordered_map<int,int> &mp) {
       if( inStart>inEnd or preStart>preEnd ) return NULL;

       TreeNode* root = new TreeNode();
       root->val = preorder[preStart];
       int inRoot = mp[preorder[preStart]];
       int numsLeft = inRoot - inStart;

       root -> left = rec( inorder, inStart, inRoot-1, preorder, preStart+1, preStart+numsLeft,mp);
       root -> right = rec( inorder, inRoot+1, inEnd, preorder, preStart+numsLeft+1, preEnd,mp);

       return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            mp[inorder[i]] = i;
        }

        return rec(inorder,0,n-1,preorder,0,n-1,mp);
    }
};