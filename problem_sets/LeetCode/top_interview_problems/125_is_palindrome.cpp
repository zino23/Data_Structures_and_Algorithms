#include <_ctype.h>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

const int diff = abs('a' - 'A');

class Solution {
public:
  bool isPalindrome(string s_) {
    string s;
    // Filter useless char
    for (auto c : s_) {
      if (isalnum(c)) {
        s.push_back(tolower(c));
      }
    }

    string s_rev(s.rbegin(), s.rend());
    return s == s_rev;
  }

  bool isPalindrome2Pointer(string s) {
    if (s.empty()) {
      return true;
    }

    int i = 0, j = s.size() - 1;

    // Initial place should be valid
    while (i < s.size() && !isalnum(s[i])) {
      i++;
    }
    while (j > 0 && !isalnum(s[j])) {
      j--;
    }

    while (i < j) {
      if (tolower(s[i]) != tolower(s[j])) {
        return false;
      }
      do {
        i++;
      } while (i < s.size() && !isalnum(s[i]));
      do {
        j--;
      } while (j > 0 && !isalnum(s[j]));
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
  return 0;
}
