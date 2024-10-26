class Solution {
public:
    vector<int> rec(string expression) {
        vector<int> ans;
        for(int i=0;i<expression.size();i++) {
            char ch = expression[i];
            if(ch=='+' or ch=='-' or ch=='*') {
                vector<int> left = rec(expression.substr(0,i));
                vector<int> right = rec(expression.substr(i+1));
                
                for(auto it:left) {
                    for(auto it1:right) {
                        if(ch=='+') ans.push_back(it+it1);
                        if(ch=='-') ans.push_back(it-it1);
                        if(ch=='*') ans.push_back(it*it1);
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(expression));
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return rec(expression);
    }
};