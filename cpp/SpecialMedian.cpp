#include <bits/stdc++.h>
using namespace std;

bool is_special(vector<int> &A) {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    double median = A[0];
    int n = A.size();

    for (int i = 0; i < n; i++) {
        if (i != 0 && A[i] == median)
            return true;

        if (A[i] <= median) {
            if (max_heap.size() + 1 - min_heap.size() > 1) {
                int top = max_heap.top();
                max_heap.pop();
                min_heap.push(top);
            }
            max_heap.push(A[i]);
        } else {
            if (min_heap.size() + 1 - max_heap.size() > 1) {
                int top = min_heap.top();
                min_heap.pop();
                max_heap.push(top);
            }
            min_heap.push(A[i]);
        }
        if (min_heap.size() == max_heap.size()) {
            median = (min_heap.top() + max_heap.top()) / (double)2;
        } else {
            median = max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
        }
    }
    return false;
}

int solve(vector<int> &A) {
    if (is_special(A))
        return 1;
    reverse(A.begin(), A.end());
    if (is_special(A))
        return 1;
    return 0;
}

int main() {
    vector<int> A = {5, 15, 1, 3, 4, 7};// 1
    // vector<int> A = {2147483647, -2147483648, 0}; // 0
    int ans = solve(A);
    cout << ans << endl;
    return 0;
}
