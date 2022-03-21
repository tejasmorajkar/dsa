#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    int n = A.size();
    int left = 0, right = 1, sm = A[0] > A[1] ? A[1] : A[0], ans = 0;
    while (left < n && right < n) {
        if (left == right) {
            right++;
            continue;
        }
        if (A[right] > sm)
            ans++;
    }
    if (A[left] > A[right])
        right++;

    return ans;
}

int main() {
    vector<int> A = {4, 3, 6, 1, 10}; // 6
    // vector<int> A = {1, 2, 4, 3, 5}; // 5
    int ans = solve(A);
    cout << ans << endl;
    return 0;
}