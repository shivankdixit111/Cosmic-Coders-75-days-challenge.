/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
     
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) { 
        if(root==NULL) return {};
        vector<int> ans;
        map<TreeNode* ,TreeNode*> parent;
        queue<TreeNode*> q;
        //for child parent relationship
        q.push(root);
        while(q.size()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->left) {
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right) {
                q.push(node->right);
                parent[node->right] = node;
            }
        }
        // from target node go to left , right and parent and explore them
        map<TreeNode*,int> vis;
        queue<pair<TreeNode*,int>> newq;
        newq.push({target,k});
        vis[target]=1;

        while(newq.size()) {
            TreeNode* node = newq.front().first;
            int k1 = newq.front().second;
            newq.pop();
            if(k1==0) {
                ans.push_back(node->val);
            } 
            if(node->left and !vis[node->left]) {
                vis[node->left]=1;
                newq.push({node->left,k1-1});
            }
            if(node->right and !vis[node->right]) {
                vis[node->right]=1;
                newq.push({node->right,k1-1});
            }         
            if(parent[node]!=NULL and !vis[parent[node]]) {
                vis[parent[node]] = 1;
                newq.push( { parent[node] , k1-1} );
            }
        }
        
        
        return ans;
    }
};