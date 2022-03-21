#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int solve(vector <int> &A) {
	int n = A.size();
	long long mod = 1000000007LL;
	long long a[n+1], Previous_greater_element[n+1], Next_greater_element[n+1], Next_smaller_element[n+1], Previous_smaller_element[n+1];
    for (int i = 0; i < n; i++) {
        a[i + 1] = A[i];
    }
    stack <long long> s;
    for (int i = 0; i <= n; i++) {
        Next_greater_element[i] = n + 1;
        Previous_greater_element[i] = 0;
        Previous_smaller_element[i] = 0;
        Next_smaller_element[i] = n + 1;
    }
    for (int i = 1; i <= n; i++) {
        if (s.empty()) {
            s.push(i);
        } else {
            while (!s.empty() && a[s.top()] <= a[i]) {
                Next_greater_element[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
    }
    while (!s.empty()) {
        s.pop();
    }
    for (int i = n; i > 0; i--) {
        if (s.empty()) {
            s.push(i);
        } else {
            while (!s.empty() && a[i] > a[s.top()]) {
                Previous_greater_element[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
    }
    while (!s.empty()) {
        s.pop();
    }
    for (int i = n; i > 0; i--) {
        if (s.empty()) {
            s.push(i);
        } else {
            while (!s.empty() && a[i] <= a[s.top()]) {
                Previous_smaller_element[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
    }
    while (!s.empty()) {
        s.pop();
    }
    for (int i = 1; i <= n; i++) {
        if (s.empty()) {
            s.push(i);
        } else {
            while (!s.empty() && a[i] < a[s.top()]) {
                Next_smaller_element[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long left = i - Previous_greater_element[i];
        long long right = Next_greater_element[i] - i;
        ans += (((left * right) % mod) * a[i]) % mod;
        ans %= mod;
        left = i - Previous_smaller_element[i];
        right = Next_smaller_element[i] - i;
        ans -= (((left * right) % mod) * a[i]) % mod;
        ans += mod;
        ans %= mod;
    }
    return ans;
}

int main() {
	vector<int> A = {4, 7, 3, 8}; // 26
	// vector<int> A = {1}; // 0
	// vector<int> A = {992387, 932142, 971117, 934674, 988917, 967890, 948508, 970347}; //1362057
	int ans = solve(A);
	printf("%d\n", ans);
	return 0;
}