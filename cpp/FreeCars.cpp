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
	    vector<pair<int, int>> v;
	    long long mod = 1000000007LL;
	    for (int i = 0; i < A.size(); i++)
	        v.push_back({A[i], B[i]});
	    sort(v.begin(), v.end());
	    int time = 0;
	    long long profit = 0;
	    priority_queue<int, vector<int>, greater<int>> pq;
	    for (int i = 0; i < v.size(); i++) {
	        if (time < v[i].first) {
	            profit += (long long)(v[i].second);
	            profit %= mod;
	            pq.push(v[i].second);
	            time++;
	        } else {
	            if (pq.top() < v[i].second) {
	                profit -= pq.top();
	                pq.pop();
	                profit += (long long)(v[i].second);
	                profit %= mod;
	                pq.push(v[i].second);
	            }
	        }
	    }
	    return (int)profit;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*
	Sample Input 1
	5 1 3 2 3 3
	5 5 6 1 3 9

	Sample output
	20
	*/

	vector<int> A = get_vector_input();
	vector<int> B = get_vector_input();
	Solution s;
	int ans = s.solve(A, B);
	cout << ans << "\n";
	return 0;
}