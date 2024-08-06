struct TrieNode {
    TrieNode* links[2];
    
    TrieNode() {
        links[0]=NULL;
        links[1]=NULL;
    }

    bool containsKey(int bit) {
        return links[bit]!=NULL;
    }
    void put(TrieNode* node, int bit) {
        links[bit] = node;
    }
    TrieNode* getbit(int bit) {
        return links[bit];
    }
};
    
TrieNode* root=NULL;
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
    TrieNode* curr = root;
    int maxNum = num;
    for(int i=31;i>=0;i--) {
        int b=-1;
        if((1<<i)&num) b=1;
        else b=0; 
        if(curr->containsKey(!b)) {  //opposite key
            maxNum = maxNum | (1<<i);
            curr = curr-> getbit(1-b);
        } else {
            if(b==1) 
                 maxNum = maxNum & (maxNum-(1<<i));  //making it unset
            curr = curr-> getbit(b);
        }
    }
    return maxNum;
}
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) { 
        root = new TrieNode();
        for(auto it:nums) {
            insert(it);
        }
        int maxi = INT_MIN;
        for(auto it:nums) {
            cout<<getMax(it)<<" ";
            maxi = max(maxi, getMax(it));
        }
        return maxi;
    }
};