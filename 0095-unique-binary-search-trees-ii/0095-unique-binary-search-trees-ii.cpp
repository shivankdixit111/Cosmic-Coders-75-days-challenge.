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
    vector<TreeNode*> build(int l,int r) {
        vector<TreeNode*> ans;
        if(l>r) {
            ans.push_back(nullptr);
            return ans;
        }

        for(int i=l;i<=r;i++) {
            vector<TreeNode*> leftSub =  build(l,i-1);
            vector<TreeNode*> rightSub =  build(i+1,r);

            for(int j=0;j<leftSub.size();j++) {
                for(int k=0;k<rightSub.size();k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftSub[j];
                    root->right = rightSub[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
          vector<TreeNode*> ans;
          return build(1,n);
    }
};