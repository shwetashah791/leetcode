class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>cache;
        int res=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(cache.count(s[i])>0){
                j=max(j,cache[s[i]]+1);
            }
            res=max(res,i-j+1);
            cache[s[i]]=i;
        }
        return res;
    }
};