#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int A, int B, vector<int> &C) {
    priority_queue<int, vector<int>, greater<int>> min_pq;
    priority_queue<int, vector<int>> max_pq;
    for (int num : C) {
        min_pq.push(num);
        max_pq.push(num);
    }
    int max_cost = 0, min_cost = 0;
    while (A--) {
        while (max_pq.top() == 0)
            max_pq.pop();
        int x = max_pq.top();
        max_pq.pop();
        max_pq.push(x - 1);
        max_cost += x;
        while (min_pq.top() == 0)
            min_pq.pop();
        int y = min_pq.top();
        min_pq.pop();
        min_pq.push(y - 1);
        min_cost += y;
    }
    return {max_cost, min_cost};
}

int main() {
    // int A = 4;
    // int B = 3;
    // vector<int> C = {2, 1, 1};
    // 5 5

    int A = 4;
    int B = 3;
    vector<int> C = {2, 2, 2};
    // 7 6

    vector<int> ans = solve(A, B, C);
    cout << ans[0] << " " << ans[1] << "\n";
    return 0;
}