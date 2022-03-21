#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
	bool is_square(long long int x)
	{
		long long int s = sqrt(x);
		return ((s * s) == x);
	}

	void helper(vector<int> &A, int n, int i, set<vector<int>> &ans)
	{
		if (i == n - 1)
		{
			if (is_square(A[i] + A[i - 1]))
			{
				ans.insert(A);
			}
			return;
		}

		for (int k = i; k < n; k++)
		{
			// Dont swap same elements
			if (i != k && A[i] == A[k])
				continue;

			swap(A[i], A[k]);
			if (i == 0 || (i > 0 && is_square(A[i] + A[i - 1])))
				helper(A, n, i + 1, ans);
			// backtrack
			swap(A[i], A[k]);
		}
	}

public:
	int solve(vector<int> &A)
	{
		int n = A.size();
		if (n == 1)
			return 0;
		set<vector<int>> ans;
		helper(A, n, 0, ans);
		return ans.size();
	}
};

int main()
{
	// vector<int> A = {2,2,2}; // 1
	vector<int> A = {1, 17, 8}; // 2
	// vector<int> A = {428, 56, 88, 12}; // 2
	// vector<int> A = {36229, 1020, 69, 127, 162, 127}; // 2
	Solution s;
	int ans = s.solve(A);
	cout << ans << endl;
	return 0;
}