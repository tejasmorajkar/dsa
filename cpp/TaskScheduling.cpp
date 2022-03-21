#include <iostream>
#include <vector>
#include <queue>
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
	int solve(vector<int> &A, vector<int> &B) {
	    queue<int> q;
	    int ans = 0;

	    for (int curr: A)
	        q.push(curr);

	    for (int curr: B) {
	        while (!q.empty() && q.front() != curr) {
	            q.push(q.front());
	            q.pop();
	            ans++;
	        }
	        ans++;
	        q.pop();
	    }
	    return ans;   
	}
};

int main() {
	vector<int> A = {2, 3, 1, 5, 4};
	vector<int> B = {1, 3, 5, 4, 2};
	// 10

	Solution s;
	int ans = s.solve(A, B);
	printf("%d\n", ans);
	return 0;
}