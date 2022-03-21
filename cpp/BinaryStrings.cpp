#include <bits/stdc++.h>
using namespace std;

int solve(string A, int B) {
    int n = A.length();
    int temp[n];
    memset(temp, 0, sizeof(temp));
    int i = 0, xr = 0, ans = 0;
    for (; i <= n - B; i++) {
        xr ^= temp[i];
        int val = A[i] - '0';
        if ((xr == 0 && val == 0) || (xr == 1 && val == 1)) {
            ans++;
            if (i + B < n) {
                temp[i + B] = 1;
            }
            xr ^= 1;
        }
    }
    while (i < n) {
        xr ^= temp[i];
        int val = A[i] - '0';
        if ((val ^ xr) ==  0)
            return -1;
        i++;
    }
    return ans;
}

int main() {
    string A = "00010110";
    int B = 3;
    // 3
    int ans = solve(A, B);
    cout << ans << "\n";
    return 0;
}