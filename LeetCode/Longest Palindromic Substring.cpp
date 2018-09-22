#include <iostream>
#include <string>
using namespace std;

int isPalindrome(string s, int lo, int hi) {

    while (hi > lo) {
        if (s[hi] != s[lo]) {
            return 0;
        }
        hi--;
        lo++;
    }
    return 1;
}

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        
        int palinLength = 0;
        string subStr = "";
        for (int i = 0;i < len-palinLength; i++) {
            
            for (int j = i+palinLength; j < len;j++) {
                if (isPalindrome(s, i, j)) {
                    palinLength = j-i+1;
                    subStr = s.substr(i, palinLength);
                }
            }
        }
        return subStr;
    }
};