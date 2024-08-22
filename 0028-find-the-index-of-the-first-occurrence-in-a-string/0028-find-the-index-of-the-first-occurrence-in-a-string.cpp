class Solution {
public:
    int strStr(string haystack, string needle) {
     if (needle.empty()) {
            return 0;
        }

        int haystackLen = haystack.length();
        int needleLen = needle.length();

        for (int i = 0; i <= haystackLen - needleLen; i++) {
            int j = 0;
            while (j < needleLen && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == needleLen) {
                return i;
            }
        }

        return -1;
    }
};