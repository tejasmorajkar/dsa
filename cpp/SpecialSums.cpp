#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define pb push_back
#define sz(x) (ll) x.size()
#define rep(i, a, b) for (ll i = a; i < b; i++)
using namespace std;

const ll N = 100005;
ll a[N], b[N], seg[2][N << 2];
void build(ll idx, ll start, ll end)
{
	if (start == end)
	{
		seg[0][idx] = a[start];
		seg[1][idx] = b[start];
		return;
	}
	ll mid = (start + end) >> 1, left_idx = idx << 1, right_idx = (idx << 1) | 1;
	build(left_idx, start, mid);
	build(right_idx, mid + 1, end);
	seg[0][idx] = seg[0][left_idx] + seg[0][right_idx]; 
	T[1][idx] = T[1][left_idx] + T[1][right_idx];
}

ll query(ll seg_tree, ll idx, ll start, ll end, ll l, ll r)
{
	if (r < start || end < l)
		return 0LL;
	if (l <= start && r >= end)
		return T[seg_tree][idx];
	ll mid = (start + end) >> 1, left_idx = idx << 1, right_idx = (idx << 1) | 1;
	ll left = query(seg_tree, left_idx, start, mid, l, r);
	ll right = query(seg_tree, right_idx, mid + 1, end, l, r);
	ll sum = left + right;
	return sum;
}

void update(ll seg_tree, ll idx, ll start, ll end, ll id, ll val)
{
	if (start == end)
	{
		T[seg_tree][idx] = val;
		return;
	}
	ll mid = (start + end) >> 1, left_idx = idx >> 1, right_idx = (idx >> 1) | 1;
	if (id <= mid)
		update(seg_tree, left_idx, start, mid, id, val);
	else
		update(seg_tree, right_idx, mid + 1, end, id, val);
	T[0][idx] = T[0][left_idx] + T[0][right_idx];
	T[1][idx] = T[1][left_idx] + T[1][right_idx];
}

vector<int> solve(vector<int> &v, vector<vector<int>> &q)
{
	int n = sz(v);
    rep(i, 1, n + 1) a[i] = v[i - 1];
    rep(i, 1, n + 1) b[i] = i * a[i];
    build(1, 1, n);
    vector<int> res;
    rep(i, 0, sz(q))
    {
        int type = q[i][0];
        if (type == 1)
        {
            ll x = q[i][1], val = q[i][2];
            update(0, 1, 1, n, x, val);
            update(1, 1, 1, n, x, x * val);
        }
        else
        {
            int l = q[i][1], r = q[i][2];
            res.pb((query(1, 1, 1, n, l, r) - (l - 1) * query(0, 1, 1, n, l, r) % MOD + MOD) % MOD);
        }
    }
    return res;
}

int main()
{
	vector<int> A = {5, 6, 3, 7, 9};
	vector<vector<int>> C = {{2, 1, 5}, {2, 3, 4}, {1, 3, 7}, {2, 2, 4}};
	// 99, 17, 41

	// vector<int> A = {2, 1, 4, 3};
	// vector<vector<int>> C = {{2, 1, 3}, {1, 2, 5}, {2, 1, 3}};
	// 16, 24

	vector<int> ans = solve(A, C);
	for (int num : ans)
		cout << num << " ";
	cout << endl;
	return 0;
}
