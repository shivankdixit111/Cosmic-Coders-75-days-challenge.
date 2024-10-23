class Solution {
public:
    int countDigitOne(int n) {
        //math problem   see the editorial
        // 1's place
        // upto 10 -> 1 one
        // upto 20 -> 2 one
        // .......

        // ten's place
        // upto 100 -> 10 one
        // upto 200 -> 20 one
        //......
        
        int ans=0;
        for(long long i=1;i<=n;i*=10) {
            long long div = i*10;
            ans += (n/div)*i + min(max(n%div-i+1,0LL),(long long)i);
        }
        return ans;
        //tc -> O(log10 n)
    }
};