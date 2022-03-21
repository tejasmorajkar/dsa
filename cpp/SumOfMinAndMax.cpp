#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	int solve(vector<int> &A, int B) {
		deque<int> max, min;
	    long long result = 0LL, mod_value = 1000000007LL;

	    for (int i = 0; i < N; i++) {
	        while(!max.empty() && A[max.back()] <= A[i]) {
	            max.pop_back();
	        }
	        while(!min.empty() && A[min.back()] >= A[i]) {
	            min.pop_back();
	        }

	        max.push_back(i);
	        min.push_back(i);

	        if (i >= B - 1) {
	        	long long max_val = (long long)A[max.front()];
	        	long long min_val = (long long)A[min.front()];
                result = (mod_value + result + min_val) % mod_value;
                result = (mod_value + result + max_val) % mod_value;
	        }
	        if (max.front() == i - B + 1) {
	            max.pop_front();
	        }
	        if (min.front() == i - B + 1) {
	            min.pop_front();
	        }
	    }
		return (int)result;
	}
};

int main() {
	vector<int> A = {2, 5, -1, 7, -3, -1, -2};
	int B = 4;
	// 18

	// vector<int> A = {2, -1, 3};
	// int B = 2;
	// 2

	Solution s;
	int ans = s.solve(A, B);
	printf("%d\n", ans);
	return 0;
}