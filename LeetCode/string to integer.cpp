class Solution {
public:
    int myAtoi(string str) {
        int found = 0;
        int neg = 0;
        int ans = 0;
        for (int i = 0; str[i]; i++) {
//             Trim both sides of the string
            if (!found) {
                if (str[i] != ' ') {
                    if ((str[i] == '+' || str[i] == '-') && (str[i+1] >= '0' && str[i+1] <= '9')) {
                        found = 1;
                    } else if (str[i] >= '0' && str[i] <= '9') {
                        found = 1;
                    } else {
                        return 0;
                    }
                }
            } else {
                if (!(str[i] >= '0' && str[i] <= '9')) {
                    break;
                }
            }
            
//             Parse the integer part
            if (found) {
                if (str[i] == '-'){
                    neg = 1;
                    continue;
                } else if (str[i] == '+') {
                    continue;
                }
                
                int digit = str[i] - '0';
//                 Check for overflow
                if (ans > INT_MAX/10) {
                    if (neg) return INT_MIN;
                    if (!neg) return INT_MAX;
                } else if (ans == INT_MAX/10 && digit > 7) {
                    if (neg && digit > 8) return INT_MIN;
                    else if (!neg) return INT_MAX;
                }
                
                ans = ans*10 + digit;
            }
        }
        return (neg?-ans: ans);
    }
};