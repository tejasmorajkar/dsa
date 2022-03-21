#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int solve (string A) {
		int n = A.length(), a_count = 0, ans = 0;
		for (int i = 0; i < n; ++i) {
			if (A[i] == 'a') {
				a_count++;
				ans += a_count;
			}
		}
		// ans = a_count * (a_count + 1)/2
		// n * (n + 1)/2
		return ans;
	}
};

int main() {
	// string A = "aab"; // 3
	// string A = "bcbc"; // 0
	string A = "fnmzxvozgkpkwuuwbnlbajogijoaxipjwwfaqefjnvfbcilerkdaeysamehgdouvspojtuvh"; // 15
	Solution s;
	int ans = s.solve(A);
	printf("%d\n", ans);
	return 0;
}