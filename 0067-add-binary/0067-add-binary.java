class Solution {
    public String addBinary(String a, String b) {
     StringBuilder ans = new StringBuilder();
        int i = a.length() - 1, j = b.length() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry != 0) {
            if (i >= 0) carry += a.charAt(i--) - '0';
            if (j >= 0) carry += b.charAt(j--) - '0';
            ans.append(carry % 2); // Append the binary digit
            carry /= 2; // Update the carry
        }

        return ans.reverse().toString(); // Reverse the result and convert to String
    }
};