#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> solve(vector<int> &nums, int A){
		int n = nums.size();
		priority_queue<int, vector<int>, greater<int>> pq;
		vector<int> result;
		for (int i = 0; i < n; i++){
			if (i < A) {
				pq.push(nums[i]);
				if (i == A - 1)
					result.push_back(pq.top());
				else 
					result.push_back(-1);
			} else {
				int x = pq.top();
				if (nums[i] > x) {
					pq.pop();
					pq.push(nums[i]);
				}	
				result.push_back(pq.top());
			}
		}
		return result;
	}
};

int main(){
	// vector<int> nums = {1, 2, 3, 4, 5, 6};
	// int A = 4;
	// -1 -1 -1 1 2 3

	vector<int> nums = {15, 20, 99, 1};
	int A = 2;
	// -1, 15, 20, 20

	Solution s;
	vector<int> ans = s.solve(nums, A);
	for (int x: ans)
		printf("%d ", x);
	printf("\n");
	return 0;
}