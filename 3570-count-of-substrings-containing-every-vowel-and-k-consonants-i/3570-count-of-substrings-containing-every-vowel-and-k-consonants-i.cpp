
#define vi vector<int>
#define vvii vector<vi>
#define vpii vector<pair<int,int>>
#define vs vector<string>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define minpq(a) priority_queue<a,vi,greater<a>> pq
#define maxpq(a) priority_queue<a> pq 
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sall(x) sort(x.begin(), x.end());
#define rall(x) sort(x.rbegin(), x.rend())
#define pb push_back 
#define in insert
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sall(x) sort(x.begin(), x.end());
#define rall(x) sort(x.rbegin(), x.rend())
#define MAX(x) *max_element(x.begin(), x.end())
#define MIN(x) *min_element(x.begin(), x.end())
#define SUM(X) accumulate(X.begin(), X.end(), 0LL)
#define rev(a) reverse(a.begin(), a.end());

bool vowel(char ch)
{
    if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u')
        return true;
    return false;
}  

class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.length();
        int cnt=0; 

        for(int i=0;i<n;i++) {
            string temp;
                umii mp;   int v=0,c=0;
            for(int j=i;j<n;j++) {
                temp.push_back(word[j]);
                if(vowel(word[j])) mp[word[j]-'a']++;
                 else c++;

                  if(mp.size()==5 and c==k) cnt++;
                
            }
        }

        return cnt;
    }
};