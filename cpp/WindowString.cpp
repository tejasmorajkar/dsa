#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	string minWindow(string A, string B) {
		int n = A.length(), m = B.length(), start = 0, length = 0, total = 0;
		if (m > n) 
			return "";
		unordered_map<char, int> freq;

		for (int i = 0; i < m; i++)
			freq[B[i]]++;

		for (int head = 0, tail = 0; tail < n; tail++) {
			// Char not present in B is present so ignore this char
			if (freq.find(A[tail]) == freq.end())
				continue;

			// Update freq since require char is found
			freq[A[tail]]--;

			// Also update chars found in current window
			if (freq[A[tail]] >= 0)
				total++;

			// All char of B found in current windows
			if (total == m) {
				// Move head if char at head is not present in B
				// or char at head is in excess
				while (freq.find(A[head]) == freq.end() || freq[A[head]] < 0) {
					// Update freq since extra char at head would be removed from window
					if (freq.find(A[head]) != freq.end())
						freq[A[head]]++;
					head++;
				}

				// update start and length
				// if length is never set or new min window found
				if (length == 0 || (tail - head + 1) < length) {
					start = head;
					length = tail - head + 1;
				}
			}
		}
		return A.substr(start, length);
	}
};

int main() {
	// string A = "ADOBECODEBANC", B = "ABC";
	string A = "Aa91b", B = "ab";
	Solution s;
	string ans = s.minWindow(A, B);
	printf("%s\n", ans.c_str());
	return 0;
}