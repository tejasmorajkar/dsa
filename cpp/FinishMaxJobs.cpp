#include <bits/stdc++.h>

using namespace std;

vector<int> get_vector_input() {
	int n;
	cin >> n;
	vector<int> A;
	while (n > 0) {
		int val;
		cin >> val;
		A.push_back(val);
		n--;
	}
	return A;
}

class Solution {
public:
	int solve(vector<int> &A, vector<int> &B) {
	    vector<pair<int,int>> v;
	    for (int i = 0; i < A.size(); i++)
	        v.push_back({B[i], A[i]});
	    sort(v.begin(), v.end());
	    int cnt = 0, prev_end = 0;
	    for (int i = 0; i < v.size(); i++) {
	        if (v[i].second >= prev_end) {
	            cnt++;
	            prev_end = v[i].first;
	        }
	    }
	    return cnt;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> A = get_vector_input();
	vector<int> B = get_vector_input();
	/*
	1)
	Sample Input
	3 3 2 6
	3 9 8 9

	Sample Output
	1

	2)
	Sample Input
	4 1 5 7 1
	4 7 8 8 8

	Sample Output
	2
	*/
	Solution s;
	int ans = s.solve(A, B);
	cout << ans << "\n";
	return 0;
}