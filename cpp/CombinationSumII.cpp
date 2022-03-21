#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void helper(vector<int> &A, int remain, int idx, vector<int> &curr, vector<vector<int> > &result)
{
	if (remain == 0)
	{
		result.push_back(curr);
		return;
	}
	else if (remain < 0)
	{
		return;
	}
	for (int i = idx; i < A.size(); ++i)
	{
		if (i > idx && A[i] == A[i - 1])
			continue;
		if (A[i] > remain)
			break;
		curr.push_back(A[i]);
		helper(A, remain - A[i], i + 1, curr, result);
		curr.pop_back();
	}
}

vector<vector<int> > combinationSum(vector<int> &A, int B)
{
	sort(A.begin(), A.end());
	vector<int> curr;
	vector<vector<int> > result;
	helper(A, B, 0, curr, result);
	return result;
}

int main()
{
	// vector<int> A = {10, 1, 2, 7, 6, 1, 5};
	// int B = 8;
	vector<int> A = {8, 10, 6, 11, 1, 16, 8};
	int B = 28;
	vector<vector<int> > ans = combinationSum(A, B);
	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < ans[i].size(); ++j)
		{
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}