class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int bit=-1;
        k--;
        if(k==0) return 'a';

        for(int i=47;i>=0;i--) {
            if((1LL<<i) & k) {
                bit = i;
                break;
            }
        }

        int x=0;
        while(bit>=0) {
            if(k>= (1LL<<(bit+1))/2 ) {
                 if(operations[bit] ==1) x--;
                k -= (1LL<<(bit+1))/2;
            }
            bit--;
        }

        cout<<x<<" "<<bit<<endl;

        // return 'a';

        return char( (-1*(x)) %26  + 'a' );
    }
};