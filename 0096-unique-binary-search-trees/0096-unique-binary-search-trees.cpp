class Solution {
public:
    int numTrees(int n) {
        // refer to this article
        // http://www.cs.cmu.edu/afs/cs/academic/class/15750-s17/ScribeNotes/lecture7.pdf
        vector<int> dp(n+1,0);
        dp[0]=1; // bst with 0 node
        dp[1]=1; // bst with 1 node
        
        for(int i=2;i<=n;i++) {
            for(int j=1;j<=i;j++) {
                dp[i] += dp[j-1] * dp[i-j]; 
                // if left subtree has j-1 nodes  right will have (i-(j-1)-1) => (i-j)
                // total bst count will be = left * right
            }
        }
        return dp[n];
    }
};