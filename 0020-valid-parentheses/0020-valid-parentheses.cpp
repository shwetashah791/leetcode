class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        unordered_map<char,char> bracketPairs={
            {')','('},
            {'}','{'},
            {']','['}       
        };
        for(char c:s){
            if(bracketPairs.count(c)){
                if(stk.empty() || stk.top()!=bracketPairs[c]){
                    return false;
                }
                stk.pop();
            }else{
                stk.push(c);
            }
        }
        return stk.empty();
    }
};