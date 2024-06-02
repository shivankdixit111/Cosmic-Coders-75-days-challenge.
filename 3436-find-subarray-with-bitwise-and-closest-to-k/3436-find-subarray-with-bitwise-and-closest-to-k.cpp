class Solution {
public:
    int minimumDifference(vector<int>& A, int k) {
        int N = A.size(), ans = abs(A[0] - k);
        for(int i = 0 ; i < N ; ++i) {
            ans = min(ans, abs(A[i] - k));
            for(int j = i - 1 ; j >= 0 ; --j) {
                if(A[j] == (A[j] & A[i]))   break;
                A[j] &= A[i];
                ans = min(ans, abs(A[j] - k));
            }
        }
        return ans;
    }
};