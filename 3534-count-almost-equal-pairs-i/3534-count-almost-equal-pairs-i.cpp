class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size(),cnt=0;

        for(int i=0;i<n;i++) {
            string t = to_string(nums[i]);
            for(int j=i+1;j<n;j++) {
                string s = to_string(nums[j]);
                if(t==s) {
                    cnt++; 
                    continue;
                } 
                 bool flag=false;
                      for(int k=0;k<t.length();k++) {
                        for(int k1=0;k1<t.length();k1++) {
                            string temp = t;
                            if(k==k1) continue;
                            swap(temp[k1],temp[k]);
                            if(!flag and stoi(temp)==stoi(s)) cnt++,flag=true;
                            if(flag) break;
                        }
                        if(flag) break;
                      }
                       for(int k=0;k<s.length();k++) {
                        if(flag) break;
                        for(int k1=0;k1<s.length();k1++) {
                            string temp = s;
                            if(k==k1) continue;
                            swap(temp[k1],temp[k]);
                            if( stoi(temp)== stoi(t)) cnt++,flag=true;
                            if(flag) break;
                        }
                      }
            }
        }
        return cnt;
    }
};