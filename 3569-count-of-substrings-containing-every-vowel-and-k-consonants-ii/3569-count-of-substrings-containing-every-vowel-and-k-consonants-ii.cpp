#define vi vector<int>
#define ll long long int
#define vvii vector<vi> 
#define all(x) x.begin(), x.end()
#define sall(x) sort(x.begin(), x.end());
#define rall(x) sort(x.rbegin(), x.rend())
#define pb push_back 
#define in insert
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++) 

bool vowel(char ch)
{
    if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u')
        return true;
    return false;
}
bool conso(char ch)
{
    if (!vowel(ch))
        return true;
    return false;
}

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        vector<char> vowel = {'a','e','i','o','u'};

        vi con(n), a(n),e(n),ii(n),o(n),u(n);
        a[0] = (word[0]=='a');
        rep(i,1,n) a[i] = a[i-1] +(word[i]=='a');
        e[0] = (word[0]=='e');
        rep(i,1,n) e[i] = e[i-1] +(word[i]=='e');
        ii[0] = (word[0]=='i');
        rep(j,1,n) ii[j] = ii[j-1] +(word[j]=='i');
        o[0] = (word[0]=='o');
        rep(i,1,n) o[i] = o[i-1] +(word[i]=='o');
        u[0] = (word[0]=='u');
        rep(i,1,n) u[i] = u[i-1] +(word[i]=='u');
        con[0] = (conso(word[0])?1:0);
        rep(i,1,n) con[i] = con[i-1] +(conso(word[i]));


        auto allvowel= [&](int l,int r) {
            if(a[r]- (l?a[l-1]:0) and e[r]- (l?e[l-1]:0) and o[r]- (l?o[l-1]:0)
            and u[r]- (l?u[l-1]:0) and ii[r]- (l?ii[l-1]:0)) return true;
            return false;
        };

        auto isvalid = [&](int l,int r) {
            if(con[r]- (l?con[l-1]:0)>=k) return true;
            return false;
        };
         auto isvalid1 = [&](int l,int r) {
            if( con[r]- (l?con[l-1]:0)<=k) return true;
            return false;
        };
  
        ll cnt=0;
        for(int i=0;i<n;i++) {
            int low=i, high =n-1,idx=-1; 
            //min poss
            while(low<=high) {
                int mid = (low+high)>>1; 
                // if(!allvowel(i,mid)) {
                //     low= mid+1;
                //     continue;
                // } 
                if(allvowel(i,mid) and isvalid(i,mid)) {
                        idx=mid;
                        high = mid-1;
                } else {
                    low = mid+1;
                }
            } 
            // max poss
            low=i, high =n-1;
            int idx1=-1;
             while(low<=high) {
                int mid = (low+high)>>1; 
                 if(!allvowel(i,mid)) {
                    low= mid+1;
                    continue;
                } 
                if(isvalid1(i,mid)) {
                        idx1=mid;
                        low = mid+1;
                } else {
                    high = mid-1;
                }
            }
            // cout<<endl;
            // cout<<i<<" "<<idx<<" "<<idx1<<endl;
             if(idx!=-1 and idx1!=-1) {
              cnt += (idx1-idx+1);
             }
        }
         return cnt;
    }
};