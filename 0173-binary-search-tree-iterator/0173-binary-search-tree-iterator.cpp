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
class BSTIterator {
public:
    void inorder(TreeNode* node, queue<TreeNode*> & st) {
        if(!node) return;

        inorder(node->left, st);
        st.push(node);
        inorder(node->right, st);
    } 

    queue<TreeNode*> st;
    BSTIterator(TreeNode* root) { 
         inorder(root,st);
    }
    
    int next() {
        int x = st.front()->val;
        st.pop();
        return x;
    }
    
    bool hasNext() {
        if(st.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */