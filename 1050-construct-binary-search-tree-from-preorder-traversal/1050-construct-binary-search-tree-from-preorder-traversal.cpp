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
    TreeNode* fun( int inBegin, int inEnd, vector<int> &inOrder, int preBegin, int preEnd, vector<int> &preOrder, map<int,int> &mp) {
         if(inBegin > inEnd or preBegin > preEnd) return NULL; 
         
         TreeNode* root = new TreeNode(preOrder[preBegin]);

         int find = mp[preOrder[preBegin]]; 
         int cnt_of_ele = (find- inBegin );

        root->left = fun( inBegin, find -1, inOrder, preBegin+1, preBegin + cnt_of_ele, preOrder, mp);
        root->right = fun( find+1, inEnd, inOrder, preBegin+ cnt_of_ele + 1, preEnd, preOrder, mp);

         return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        int n= inorder.size();
        map<int,int> mp;
        for(int i=0;i<n;i++) {
            mp[inorder[i]]=i;
        }
 
        return fun(0,n-1,inorder,0,n-1,preorder,mp);

    }
};