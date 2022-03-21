#include <bits/stdc++.h>
using namespace std;

int mice(vector<int> &A, vector<int> &B) {
    priority_queue<int, vector<int>, greater<int>> pq_a, pq_b;
    for (int i = 0; i < A.size(); i++) {
        pq_a.push(A[i]);
        pq_b.push(B[i]);
    }
    int ans = INT_MIN;
    while (!pq_a.empty() && !pq_b.empty()) {
        int x = pq_a.top();
        pq_a.pop();
        int y = pq_b.top();
        pq_b.pop();
        int z = abs(x - y);
        ans = max(ans, z);
    }
    return ans;
}

// Editorial
// using sorting
int mice2(vector < int > & A, vector < int > & B) {
    int N = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans = 0;

    for (int i = 0; i < N; ++i) {
        ans = max(ans, abs(A[i] - B[i]));
    }

    return ans;
}

int main() {
    vector<int> A = { -4, 2, 3};
    vector<int> B = {0, -2, 4};
    // 2
    int ans = mice(A, B);
    cout << ans << "\n";
    return 0;
}