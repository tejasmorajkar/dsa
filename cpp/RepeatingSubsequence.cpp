#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long mul(long long a, long long b) {return (a * b) % MOD;}
void fast_io() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

int anytwo(string A) {
	int n = A.length();
	int lcs[n + 1][n + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				lcs[i][j] = 0;
			else if (A[i - 1] == A[j - 1] && i != j)
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}
	return lcs[n][n] >= 2 ? 1 : 0;
}

int main() {
	fast_io();
	int tc = 1;
	cin >> tc;
	while (tc--) {
		string A;
		cin >> A;
		int ans = anytwo(A);
		cout << ans << "\n";
	}
	return 0;
}