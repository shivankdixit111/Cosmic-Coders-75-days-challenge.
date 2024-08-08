struct TrieNode {
    TrieNode* links[2];
    TrieNode() {
        links[0]=NULL;
        links[1]=NULL;
    }
    bool containsKey(int bit) {
        return (links[bit]!=NULL);
    }
    void put(TrieNode* node, int bit) {
        links[bit] = node;
    }
    TrieNode* getbit(int bit) {
        return links[bit];
    }
};
TrieNode* root = NULL;
void insert(int num) {
    TrieNode* curr = root;
    for(int i=31;i>=0;i--) {
        int b=-1;
        if((1<<i)&num) b=1;
        else b=0;
        if(!curr->containsKey(b)) {
             curr->put(new TrieNode(), b);
        }
        curr=curr->getbit(b);
    }
}

   int getMax(int num) {
    int maxNum=num, take=0;
    TrieNode* curr = root;

    for(int i=31;i>=0;i--) {
        int b=-1;
        if((1LL<<i) & num) b=1;
        else b=0;
        // if opposite bit exists
       if(curr->containsKey(!b) )  {
                curr = curr-> getbit(1-b); 
                maxNum = maxNum | (1<<i);
        } else { 
            if(b==1)
                 maxNum = maxNum & (maxNum-(1LL<<i));  //making it unset
            curr = curr-> getbit(b);
        }
    }
    return maxNum;
}
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        root = new TrieNode();
        
        //inserting the values into Trie data structure
        bool zero=false;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<int> ans(queries.size());

        vector<pair<int,pair<int,int>>> offlinequeries;
        for(int i=0; i<queries.size(); i++) {
            int num = queries[i][0];
            int limit = queries[i][1];
            
            offlinequeries.push_back({limit,{num,i}});
        } 
        sort( offlinequeries.begin(), offlinequeries.end() );
        
        int i=0;
        for(auto it: offlinequeries ) {
            int limit = it.first;
            int num = it.second.first;
            int idxq = it.second.second;

            while(i<n and nums[i]<=limit) {
                insert(nums[i]);
                i++;
            }
            if(i==0) {
                ans[idxq] = -1;
            } else {
                ans[idxq] = getMax(num);
            }
        }
        return ans;
    }
};