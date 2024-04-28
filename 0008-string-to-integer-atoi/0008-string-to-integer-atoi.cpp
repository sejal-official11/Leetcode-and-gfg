class Solution {
public:

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}
    int myAtoi(string s) {

        int index = 0;

        while(index < s.length() && s[index] == ' ') {
            index++;
        }

        
        bool sign = true;
        if(index < s.length())
        {
             if(s[index] == '+') {
            sign = true;
            index++;
        }
        else if(s[index] == '-') {
            sign = false;
            index++;
        }
        }

        int ans = 0;
        while(index < s.length() && isDigit(s[index])) {
            int digit = s[index] -'0';

            if((ans > INT_MAX/10) || (ans == (INT_MAX / 10) && digit > 7)) {
                return sign ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;

            index++;
        }

        return sign ? ans : -1*ans;
       
        
        
    }
};