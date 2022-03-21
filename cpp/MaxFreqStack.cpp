#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

class Solution {
private:
	unordered_map<int, int> freq_map;
	unordered_map<int, stack<int>> freq_stack_map;
	int max_freq = 0;

	void push(int x) {
		int curr = (++freq_map[x]);
		if (curr > max_freq) {
			max_freq = curr;
		}
		freq_stack_map[curr].push(x);
	}

	int pop() {
		int ans = freq_stack_map[max_freq].top();
		freq_stack_map[max_freq].pop();
		freq_map[ans]--;
		if (freq_stack_map[max_freq].empty()) {
			max_freq--;
		}
		return ans;
	}

public:
	vector<int> solve(vector<vector<int> > &A) {
		int n = A.size();
		vector<int> result;
		for (int i = 0; i < n; ++i) {
			int op = A[i][0], x = A[i][1];
			if (op == 1) {
				push(x);
				result.push_back(-1);
			} else {
				int res = pop();
				result.push_back(res);
			}
		}
		return result;
	}
};

int main() {
	// vector<vector<int>> A = {{1,5},{1,7},{1,5},{1,7},{1,4},{1,5},{2,0},{2,0},{2,0},{2,0}};
	// vector<vector<int>> A = {{1,8},{1,6},{2,0},{2,0},{1,7}};
	// vector<vector<int>> A = {{1,4},{2,0},{1,9},{2,0},{1,6},{1,6},{2,0}};
	vector<vector<int>> A = {{1,9},{2,0},{1,2},{2,0},{1,6},{1,2}};

	Solution s;
	vector<int> ans = s.solve(A);
	for (int num: ans)
		printf("%d ", num);
	printf("\n");
	return 0;
}