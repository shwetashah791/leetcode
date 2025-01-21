class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> digitToLetters={
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        vector<string>result;
        string combination;
        backtrack(digits,0,combination,digitToLetters,result);
        return result;
    }
    private:
    void backtrack(const string& digits,int index,string& combination,
    const vector<string>& digitToLetters,vector<string>& result){
        if(index==digits.size()){
            result.push_back(combination);
            return;
        }
        string letters=digitToLetters[digits[index]-'0'];
        for(char letter:letters){
            combination.push_back(letter);
            backtrack(digits,index+1,combination,digitToLetters,result);
            combination.pop_back();
        }
    }
};