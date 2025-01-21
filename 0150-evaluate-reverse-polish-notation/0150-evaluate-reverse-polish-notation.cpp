class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for(const auto& token:tokens){
            if(isOperator(token)){
                int b=stack.top();
                stack.pop();
                int a=stack.top();
                stack.pop();
                stack.push(evaluate(a,b,token));
            }else{
                stack.push(stoi(token));
            }
        }
        return stack.top();
    }
    private:
    bool isOperator(const string& token){
        return token=="+" || token=="-" || token=="*" || token=="/";
    }
    int evaluate(int a,int b,const string& op){
        if(op=="+") return a+b;
        if(op=="-") return a-b;
        if(op=="*") return a*b;
        if(op=="/") return a/b;
        throw invalid_argument("Invalid operator");
    }
};