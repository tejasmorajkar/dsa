#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> running_median(vector<int> &nums) {
		priority_queue<int> max_heap;
		priority_queue<int, vector<int>, greater<int>> min_heap;
		int n = nums.size();
		vector<int> result;
		int median = nums[0];
		max_heap.push(nums[0]);
		result.push_back(median);
		for (int i = 1; i < n; i++) {
			if (nums[i] >= median) {
				if (min_heap.size() <= max_heap.size()) {
					min_heap.push(nums[i]);
				} else {
					max_heap.push(min_heap.top());
					min_heap.pop();
					min_heap.push(nums[i]);
				}
			} else {
				if (max_heap.size() <= min_heap.size()) {
					max_heap.push(nums[i]);
				} else {
					min_heap.push(max_heap.top());
					max_heap.pop();
					max_heap.push(nums[i]);
				}
			}

			if (min_heap.size() == max_heap.size()) {
				median = max_heap.top();
			} else if (min_heap.size() > max_heap.size()) {
				median = min_heap.top();
			} else {
				median = max_heap.top();
			}

			result.push_back(median);
		}
		return result;
	}
};

int main() {
	vector<int> A = {5,17,100,11}; // { 5,5,17,11}
	// vector<int> A = {1,2,5,4,3}; // {1,1,2,2,3}
	// vector<int> A = {100}; // {100}
	Solution s;
	vector<int> ans = s.running_median(A);
	for (int x: ans)
		printf("%d ", x);
	printf("\n");
	return 0;
}