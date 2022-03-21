#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	vector<int> generate_lps(string str) {
		int n = str.length();
		vector<int> lps(n);
		lps[0] = 0;
		int i = 0, j = 1;
		while (j < n) {
			if (str[i] == str[j]) {
				i++;
				lps[j] = i;
				j++;
			} else {
				if (i != 0) {
					i = lps[i - 1];
				} else {
					lps[j] = 0;
					j++;
				}
			}
		}
		return lps;
	}

public:
	int solve(string A) {
		string rev = A;
		reverse(rev.begin(), rev.end());
		string str = A + "$" + rev;
		vector<int> lps = generate_lps(str);
		return (A.length() - lps.back());
	}
};

int main() {
	// string A = "abc"; // 2
	// string A = "abba"; // 0
	// string A = "babb"; // 1 
	string A = "zrzbmnmgqoo"; // 8
	Solution s;
	int ans = s.solve(A);
	printf("%d\n", ans);
}