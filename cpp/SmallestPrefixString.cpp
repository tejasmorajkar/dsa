#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	string solve(string A, string B) {
		string ans = "";
		ans += A[0];
		int i = 1;
		int j = 0;
		while (i < A.length() && A[i] < B[j]) {
			ans += A[i];
			i++;
		}
		ans += B[j];
		return ans;
	}
};

int main() {
	// string A = "abba", B = "cdd"; // abbac
	// string A = "acd", B = "bay"; // ab
	string A = "ababa", B = "ahahahah"; // aa
	Solution s;
	string ans = s.solve(A, B);
	printf("%s\n", ans.c_str());
	return 0;
}