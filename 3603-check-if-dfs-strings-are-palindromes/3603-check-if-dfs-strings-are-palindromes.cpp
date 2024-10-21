#define MAXLEN 100010

constexpr uint64_t mod = (1ULL << 61) - 1;

const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);

uint64_t base_pow[MAXLEN];

int64_t modmul(uint64_t a, uint64_t b){
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & mod) + (ret >> 61);
    ret = (ret & mod) + (ret >> 61);
    return ret - 1;
}

void init(){
    base_pow[0] = 1;
    for (int i = 1; i < MAXLEN; i++){
        base_pow[i] = modmul(base_pow[i - 1], base);
    }
}

struct PolyHash{
    /// Remove suff vector and usage if reverse hash is not required for more speed
    vector<int64_t> pref, suff;

    PolyHash() {}

    template <typename T>
    PolyHash(const vector<T>& ar){
        if (!base_pow[0]) init();

        int n = ar.size();
        assert(n < MAXLEN);
        pref.resize(n + 3, 0);
        suff.resize(n + 3, 0);

        for (int i = 1; i <= n; i++){
            pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
            if (pref[i] >= mod) pref[i] -= mod;
        }

         for (int i = n; i >0; i--){
            suff[i] = modmul(suff[i+1], base) + ar[i - 1] + 997;
            if (suff[i] >= mod) suff[i] -= mod;
        }

    }

    PolyHash(const char* str)
        : PolyHash(vector<char> (str, str + strlen(str))) {}
   
    PolyHash(const std::string& str)
        : PolyHash(vector<char>(str.begin(), str.end())) {}

    uint64_t get_hash(int l, int r){
        int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
        return h < 0 ? h + mod : h;
    }

    uint64_t rev_hash(int l, int r){
        int64_t h = suff[l +1] - modmul(base_pow[r - l + 1], suff[r+2]);
        return h < 0 ? h + mod : h;
    }
};
bool generated = false;
#define i64 uint64_t


class Solution {
public:
    void euler_tour(int node,int parent, vector<vector<int>> &adj, int &timer, string &euler,
    vector<int> &sz, vector<int> &outTime, string &s) {
          
          for(auto it:adj[node]) {
             if( it != parent) {
                 euler_tour(it, node, adj, timer, euler, sz, outTime, s);
                 sz[node] += sz[it];
             }
          }
          outTime[node] = timer++;
          euler.push_back(s[node]);
          sz[node] += 1;
    }
   
    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n= parent.size();
         vector<vector<int>> adj(n+1);
        for(int i=1;i<n;i++) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }

        string euler="";
        int timer=0;
        vector<int> sz(n+1,0), outTime(n+1,0);

        euler_tour(0,-1,adj,timer,euler,sz,outTime,s);
        
        PolyHash ph(euler);
        vector<bool> ans(n,0);

        for(int i=0;i<n;i++) {
            int idx = outTime[i] - sz[i] + 1;

            if(ph.get_hash(idx,outTime[i]) == ph.rev_hash(idx,outTime[i])) ans[i] = true;
            else ans[i] = false;
        }
        return ans;
    }
};