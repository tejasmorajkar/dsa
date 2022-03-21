#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	int solve(int A, int B) {
		int n = A;
		long long int sum = 0LL;
		vector<int> seq;
		vector<long long int> prefix_sum;
		for (int i = 1; i <= A; i++) {
			seq.push_back(i);
			sum += i;
			prefix_sum.push_back(sum);
		}
		
		int start = 0, end = n - 1;
		while (start <= end) {
			int mid = start + (end - start)/2;
			int curr_sum = (int)prefix_sum[mid];
			if (curr_sum == B) {
				return mid;
			} else if (curr_sum > B) {
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}
		if (prefix_sum[end] < sum)
			return end;
	}
};

int main() {
	// int A = 8, B = 21;
	// Ideal sequence:	 	1 2 3 4 5 6 7 8
	// Prefix sum:			1 3 6 10 15 21 28 36
	// Possible sequence: 	1 2 3 3 3 3 3 3
	// Ans is 5 since we have to change 4 5 6 7 8 to 3 3 3 3 3 to get ideal sequence

	// int A = 3, B = 5;
	// Ideal sequence:		1 2 3
	// Prefix sum:			1 3 6
	// Possible sequence:	1 2 2
	// Ans is 1 since we have to change 3 to 2 to get ideal sequence

	int A = 6, B = 7;
	// Ideal sequence:		1 2 3 4 5 6
	// Prefix sum:			1 3 6 10 15 21
	// Possible sequence:	1 1 1 1 1 2
	// Ans is 5 since we have to change 2 3 4 5 6 to 1 1 1 1 2
	Solution s;
	int ans = s.solve(A, B);
	printf("%d\n", ans);
	return 0;
}