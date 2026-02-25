class Solution {
public:
    bool isPalindrome(string s) {
        
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            while (start < end && !isalnum(s[start]))
                start++;
//isalnum is a cpp function to check alphanumeric or not (A-Z,a=z,0-9)
            while (start < end && !isalnum(s[end]))
                end--;
            if (tolower(s[start]) != tolower(s[end]))
                return false;
            start++;
            end--;
        }
        return true;
    }
};