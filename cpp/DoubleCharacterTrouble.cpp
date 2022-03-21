#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string solve(string A) {
    int n = A.length();
    stack<char> s;
    s.push(A[0]);
    for (int i = 1; i < n; i++) {
      if (not s.empty() && A[i] == s.top()) {
        s.pop();
      } else {
        s.push(A[i]);
      }
    }
    string ans = "";
    while (not s.empty()) {
      char c = s.top();
      ans.push_back(c);
      s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  // string A = "abccbc";
  string A = "aaaaa";
  Solution s;
  string ans = s.solve(A);
  printf("%s\n", ans.c_str());
  return 0;
}