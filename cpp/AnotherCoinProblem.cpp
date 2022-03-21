#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int solve(int A) {
	int ans = 0;
	while (A > 0) {
		ans += (A % 5);
		A /= 5;
	}
	return ans;
}

int main() {
	int A = 9; // 5
	// int A = 47; // 7
	int ans = solve(A);
	cout << ans << endl;
	return 0;
}
