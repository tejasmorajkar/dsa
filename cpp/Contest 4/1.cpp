#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long mul(long long a, long long b) {
	return (a * b) % MOD;
}
void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string solve(vector<int> &A) {
	map<int, int> freq;
	for (int num : A) {
		freq[num]++;
	}
	if (freq.size() == 2) {
		// freq of first entry and second shud b same
	} else {
		return "LOSE";
	}
}

int main() {
	fast_io();
	int tc = 1;
	cin >> tc;
	while (tc--) {
	}
	return 0;
}