class Solution {
public:
    vector<int> manacher_odd(string temp) {
        int n=temp.length(), l=1,r=1;
        temp="$"+temp+"^"; 
        vector<int> p(n+2,0);
        for(int i=1;i<=n;i++) {
            //for mirror image of pal sub
            p[i] = max( 0 , min( r-i, p[l+(r-i)] ) ); 
            //trivial algorithm
            while(temp[i-p[i]]==temp[i+p[i]]) {
                p[i]++;
            }
            if(i+p[i]>r) {
                l=i-p[i];       r=i+p[i];  //stores the range of max longest pal sub
            }
        }
        return vector<int> (begin(p)+1, end(p)-1);
    }
    string shortestPalindrome(string s) {
        string temp="";
        for(auto it:s) {
            temp+=string("#")+it;
        }
        temp+=(string)"#";
        vector<int> mana= manacher_odd(temp);
        // cout<<temp<<endl;
        // for(auto it:mana) cout<<it<<" ";
        // cout<<endl;

        string minsub="";
        int maxi=INT_MIN,idx=-1;
        for(int i=0;i<mana.size();i++) {
            if(mana[i]-i==1) {
                maxi=max(maxi,mana[i]);
                idx=i+maxi-1;
                // cout<<i<<" "<<mana[i]<<endl;
            }
        }
        // cout<<idx<<endl;
        for(int i=idx;i<temp.size();i++) {
            if(temp[i]=='#') continue;
            else minsub+=temp[i];
        }
        reverse(minsub.begin(),minsub.end());
        return (minsub+s);
    }
};