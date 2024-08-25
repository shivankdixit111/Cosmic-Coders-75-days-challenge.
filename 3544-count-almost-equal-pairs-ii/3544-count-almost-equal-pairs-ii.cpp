const int N = (int)1e7+5;
int vis[N],mp[N];
class Solution {
public:
    int countPairs(vector<int>& nums) {
         int n = nums.size(),ans=0;
           vector<int> strlist,total;
            total.reserve(300 * nums.size());

            auto apply2 = [&](string& s) {
              for(int i=0;i<7;i++) {
                 for(int j=1;j<7;j++) {
                    swap(s[i],s[j]);
                    strlist.push_back(stoi(s));
                    swap(s[i],s[j]);
                 }
              }
           };

            auto apply= [&](string& s) {
               for(int i=0;i<7;i++) {
                for(int j=i+1;j<7;j++) {
                    swap(s[i],s[j]);
                    apply2(s);
                    swap(s[i],s[j]);
                }
              }
              for(auto it:strlist) { 
                  if(vis[it]==0) {
                     vis[it]=1;
                     total.push_back(it);
                     mp[it]++;
                  }
              }
              for(auto it:strlist) {
                vis[it]=0;
              }
                strlist.clear();
           };

        for(int i=0;i<n;i++) {
            string num = to_string(nums[i]);
            reverse(num.begin(),num.end());
            while(num.length()<7) {
                num.push_back('0');
            }
            reverse(num.begin(),num.end());
            
                ans += mp[stoi(num)];
                
            apply(num);
        }
        for(auto it:total) {
            mp[it]=0;
        }
        return ans;
    }
};