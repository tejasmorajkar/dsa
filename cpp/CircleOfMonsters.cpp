#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (; t; --t) 
    {
        int m;
        cin >> m;
        vector<long long> A;
        vector<long long> B;
        for (int i = 0; i < m; i++) 
        {
            long long h;
            cin >> h;
            long long d;
            cin >> d;
            A.push_back(h);
            B.push_back(d);
        }
        int n = A.size();
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                ans += max(0LL, A[0] - B[n - 1]);
            else
                ans += max(0LL, A[i] - B[i - 1]);
        }
        long long minBullets = 0;
        for (long i = 0; i < n; i++)
        {
            if (i == 0)
                minBullets = A[0] + ans - max(0LL, A[0] - B[n - 1]);
            else
                minBullets = min(minBullets, A[i] + ans - max(0LL, A[i] - B[i - 1]));
        }
        cout << minBullets << endl;
    }
    return 0;
}
