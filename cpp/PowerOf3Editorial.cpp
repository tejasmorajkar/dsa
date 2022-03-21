#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> v) {
    for (int num : v)
        cout << num << " ";
    cout << endl;
}

int power(int x, int y, int p) {
    int res = 1; // Initialize result
    x = x % p; // Update x if it is more than or
    // equal to p
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int modInverse(int a, int m) {
    return power(a, m - 2, m);
}

int MOD = 3, n;
class SegTree {
    vector < int > bit, mod;
public:
    SegTree(string & A);
    void build(string & A, int start, int end, int ind);
    void update(int ind, int start, int end, int l, int val);
    int get(int ind, int start, int end, int l, int r);
};

// constructor
SegTree::SegTree(string & A) {
    bit.resize(4 * A.size(), 0);
    mod.resize(4 * A.size(), 0);
    build(A, 0, A.size() - 1, 0);
}

// build segment tree
void SegTree::build(string & A, int start, int end, int ind) {

}

// update the value
void SegTree::update(int ind, int start, int end, int l, int val) {
    int r = l;
    if (start > r || l > end || start > end)
        return;
    if (start >= l && end <= r) {
        bit[ind] = 1;
        mod[ind] = bit[ind] * power(2, n - 1 - end, 3);
        return;
    }
    int mid = (start + end) / 2;
    update(2 * ind + 1, start, mid, l, 1);
    update(2 * ind + 2, mid + 1, end, l, 1);
    mod[ind] = (mod[2 * ind + 1] + mod[2 * ind + 2]) % MOD;
}

// find the sum in the range l to r
int SegTree::get(int ind, int start, int end, int l, int r) {
    if (start > end || start > r || end < l)
        return 0;
    if (start >= l && end <= r) {
        return mod[ind];
    }
    int mid = (start + end) / 2;
    int left = get(2 * ind + 1, start, mid, l, r);
    int right = get(2 * ind + 2, mid + 1, end, l, r);
    return (left + right) % MOD;
}

vector < int > solve(string A, vector < vector < int > > & B) {
    n = A.size();
    int m = B.size();

    // create segment tree
    SegTree st(A);
    vector < int > ans;
    for (int i = 0; i < m; i++) {
        if (B[i][0] == 0) {
            int l = B[i][1] - 1, r = B[i][2] - 1;
            // get the sum from l to r
            int val = st.get(0, 0, n - 1, l, r);
            // multiply by modulo inverse 3 of 2^(n-1-r)
            val = (val * modInverse(power(2, n - 1 - r, 3), 3)) % 3;
            ans.push_back(val);
        } else {
            // update 1 at index B[i][1] - 1
            st.update(0, 0, n - 1, B[i][1] - 1, 1);
            ans.push_back(-1);
        }
    }
    return ans;
}

int main() {
    string A = "10010";
    vector<vector<int>> B = {{0, 3, 5}, {0, 3, 4}, {1, 2, -1}, {0, 1, 5}};
    // 2, 1, -1, 2

    // string A = "11111";
    // vector<vector<int>> B = {{0, 2, 4}, {1, 2, 4}, {0, 2, 4}};
    // 1 -1 1

    vector<int> ans = solve(A, B);
    print_vector(ans);
    return 0;
}