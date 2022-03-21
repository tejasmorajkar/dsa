#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<ll, ll>
#define vi vector<ll>
#define vii vector<pii>
#define mi map<ll, ll>
#define mii map<pii, ll>
#define all(a) (a).begin(), (a).end()
#define x first
#define y second
#define sz(x) (ll) x.size()
#define endl '\n'
#define MOD 1000000007
#define rep(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

const ll N = 100005;

ll n, q, a[N], b[N], seg[2][N << 2];

void build(ll node, ll start, ll end)
{

    if (start == end)
    {

        seg[0][node] = a[start];

        seg[1][node] = b[start];

        return;
    }

    ll mid = (start + end) >> 1;

    build(node << 1, start, mid);

    build(node << 1 | 1, mid + 1, end);

    seg[0][node] = seg[0][node << 1] + seg[0][node << 1 | 1];

    seg[1][node] = seg[1][node << 1] + seg[1][node << 1 | 1];
}

ll query(ll f, ll node, ll start, ll end, ll l, ll r)
{

    if (l <= start && r >= end)
        return seg[f][node];

    if (r < start || l > end)
        return 0;

    ll mid = (start + end) >> 1;

    ll ans1 = query(f, node << 1, start, mid, l, r);

    ll ans2 = query(f, node << 1 | 1, mid + 1, end, l, r);

    return (ans1 + ans2);
}

void update(ll f, ll node, ll start, ll end, ll x, ll val)
{

    if (start == end)
    {

        seg[f][node] = val;

        return;
    }

    ll mid = (start + end) >> 1;

    if (start <= x && x <= mid)
        update(f, node << 1, start, mid, x, val);

    else
        update(f, node << 1 | 1, mid + 1, end, x, val);

    seg[0][node] = seg[0][node << 1] + seg[0][node << 1 | 1];

    seg[1][node] = seg[1][node << 1] + seg[1][node << 1 | 1];
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