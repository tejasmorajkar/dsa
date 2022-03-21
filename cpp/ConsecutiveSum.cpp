#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	int solve(int A) {
		int count = 0;
		int max_k = 1+ (int)sqrt(2*A);
		for (int k = 1; k < max_k; k++) {
			int t = A - ((k * (k - 1))/2);
			if (t % k == 0)
				count++;
		}
		return count;
	}
};

int main() {
	// int A = 5; // 2 i.e 2 + 3 and 5
	// int A = 15 // 1 + 2 + 3 + 4 + 5, 4 + 5 + 6
	// int A = 1; // 1
	int A = 3; // 2
	Solution s;
	int ans = s.solve(A);
	printf("%d\n", ans);
	return 0;
}