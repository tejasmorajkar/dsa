#include <bits/stdc++.h>
using namespace std;

struct Fraction {
	long double val;
	int num;
	int deno;
	Fraction(long double v, int n, int d) {
		val = v;
		num = n;
		deno = d;
	}
};

struct FractionComparator {
	bool operator()(Fraction const &f1, Fraction const &f2) {
		return f1.val > f2.val;
	}
};

vector<int> solve(vector<int> &A, int B) {
	int n = A.size();
	priority_queue<Fraction, vector<Fraction>, FractionComparator> pq;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int num = A[i], deno = A[j];
			long double val = (long double)num / deno;
			Fraction f = Fraction(val, num, deno);
			pq.push(f);
		}
	}
	int num, deno;
	while (B > 0) {
		Fraction f = pq.top();
		pq.pop();
		num = f.num;
		deno = f.deno;
		B--;
	}
	vector<int> ans = {num, deno};
	return ans;
}

// Editorial
#define y second.second
#define x second.first

vector <int> solve2(vector <int> &A, int B) {
	int K = B;
	priority_queue <pair <double, pair<int, int>>, vector <pair <double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> q;
	unordered_map <int, int> nxt;
	int n = A.size();

	for (int i = n - 1; i > 0; i--)
		nxt[A[i]] = A[i - 1];

	double last = A[n - 1], d;
	nxt[1] = 0;

	for (int i = 0; i < n; i++) {
		d = (double) A[i] / last;
		q.push(make_pair(d, make_pair(A[i], last)));
	}

	while (q.size() > 0 && K > 0) {
		K--;
		if (K == 0)
			break;

		pair <double, pair <int, int>> p = q.top();
		q.pop();
		if (nxt[p.y] != 0) {
			p.y = nxt[p.y];
			d = (double) p.x / (double) p.y;
			q.push(make_pair(d, p.second));
		}
	}

	vector <int> ret(2);
	ret[0] = q.top().second.first;
	ret[1] = q.top().second.second;

	return ret;
}

// Using Binary search
class Solution {
private:
	vector<int> findClosestFraction(vector<int>& arr, long double target) {
		int n = arr.size();
		int i = 0, num = arr[0], deno = arr[n - 1], count = 0;

		for (int j = 1; j < n; j++) {
			while (arr[i] <= target * arr[j])
				i++;
			count += i;
			if (i > 0 && arr[i - 1] * deno > num * arr[j]) {
				num = arr[i - 1];
				deno = arr[j];
			}
		}
		return {count, num, deno};
	}

public:
	vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
		int n = arr.size();
		long double low = (long double)arr[0] / arr[n - 1], high = 1;

		while (low < high) {
			long double mid = (low + high) / 2;
			vector<int> v = findClosestFraction(arr, mid);
			int count = v[0], num = v[1], deno = v[2];
			if (count > k) {
				high = mid;
			} else if (count < k) {
				low = mid;
			} else {
				return {num, deno};
			}
		}

		return {};
	}
};

int main() {
	// vector<int> A = {1, 2, 3, 5};
	// int B = 3;
	// 2 5

	// vector<int> A = {1, 7};
	// int B = 1;
	// 1 7

	vector<int> A = { 1, 719, 983, 9293, 11321, 14447, 16411, 17881, 22079, 28297};
	int B = 42;
	// 17881 22079
	vector<int> ans = solve(A, B);
	for (int num : ans)
		cout << num << " ";
	cout << "\n";
	return 0;
}