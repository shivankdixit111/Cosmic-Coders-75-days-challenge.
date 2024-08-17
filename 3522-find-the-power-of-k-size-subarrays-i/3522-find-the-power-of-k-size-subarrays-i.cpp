class Solution {
public:
    vector<int> resultsArray(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> ans;
        
        for(int i=0;i<=n-k;i++) {
            vector<int> temp;
            int j=i;
            for( j=i;j<(i+k-1);j++) {
              if(arr[j]==arr[j+1]-1)
               temp.push_back(arr[j]);
               else break;
            }
            for(auto it:temp) cout<<it<<" ";
            cout<<endl;
            if(temp.size()==k-1 and j<n) {
                temp.push_back(arr[j]);
                ans.push_back(temp[temp.size()-1]);
            } else ans.push_back(-1);
        }
        return ans;
    }
};