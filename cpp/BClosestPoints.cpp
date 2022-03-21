#include <bits/stdc++.h>
using namespace std;

struct Point {
	long long index;
	long long distance;
	Point(long long i, long long d) {
		index = i;
		distance = d;
	}
};

struct PointComparator {
	bool operator()(Point const &p1, Point const &p2) {
		return p1.distance > p2.distance;
	}
};

vector<vector<int>> solve(vector<vector<int>> &A, int B) {
	priority_queue<Point, vector<Point>, PointComparator> pq;
	for (long long i = 0; i < A.size(); i++) {
		long long x = (long long)A[i][0];
		x *= x;
		long long y = (long long)A[i][1];
		y *= y;
		long long d = x + y;
		Point p = Point(i, d);
		pq.push(p);
	}
	vector<vector<int>> result;
	while (B--) {
		Point p = pq.top();
		pq.pop();
		int x = A[p.index][0], y = A[p.index][1];
		vector<int> ans = {x, y};
		result.push_back(ans);
	}
	return result;
}

// Editorial
vector < vector < int > > solve2(vector < vector < int > > & A, int B) {
	vector < pair < long long, int >> v;
	int n = A.size();
	for (int i = 0; i < n; ++i) {
		long long x = A[i][0];
		long long y = A[i][1];
		v.push_back({
			x * x + y * y,
			i
		});
	}
	// Creating MinHeap in O(N)
	priority_queue < pair < long long, int >, vector < pair < long long, int > >,
	               greater < pair < long long, int > > > minHeap(v.begin(), v.end());
	vector < vector < int > > ans;
	// Extract B values
	for (int i = 0; i < B; i++) {
		pair < long long, int > val = minHeap.top();
		minHeap.pop();
		vector < int > temp = A[val.second];
		ans.push_back(temp);
	}
	return ans;
}

int main() {
	// vector<vector<int>> A = {{1, 3}, { -2, 2}};
	// int B = 1;
	// -2 2

	vector<vector<int>> A = {{1, -1}, {2, -1}};
	int B = 1;
	// 1 -1

	vector<vector<int>> ans = solve(A, B);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i][0] << " " << ans[i][1] << "\n";
	return 0;
}
