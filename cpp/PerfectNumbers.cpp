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
	string solve(int A) {
	    queue<string> q;
	    q.push("1");
	    q.push("2");
	    vector<string> ans;
	    int n = A;
	    while (n > 0) {
	        string str = q.front();
	        q.push(str + "1");
	        q.push(str + "2");
	        string rev_str = str;
	        reverse(rev_str.begin(), rev_str.end());
	        string temp = str + rev_str;
	        ans.push_back(temp);
	        q.pop();
	        n--;
	    }
	    return ans[A - 1];
	}
};

int main() {
	int A = 4; // "1221"
	Solution s;
	string ans = s.solve(A);
	printf("%s\n", ans.c_str());
	return 0;
}