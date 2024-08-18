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
    int widthOfBinaryTree(TreeNode* root) {
        long first=0,last=0;
        long ans = LONG_MIN;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(q.size()) {
            int mm = q.front().second;
            int size = q.size();
            bool flag=true;
            for(int i=0;i<size;i++) {
                TreeNode* node = q.front().first;
                long long cnt = q.front().second-mm;
                q.pop();
                if(i==0) 
                    first = cnt;  
                if(i==size-1) last = cnt;

                if(node->left) q.push({node->left,2*cnt+1});
                if(node->right) q.push({node->right,2*cnt+2});

            }
             ans = max(ans, (last-first+1)); 
        }     
           cout<<ans<<endl;
        return ans;
    }
};