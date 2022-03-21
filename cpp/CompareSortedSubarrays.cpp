#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<int, long long int> Hash;

long long int rand46()
{
    long long int ret = 0LL;
    ret |= rand();
    ret |= (((long long int)rand())<<15);
    return ret;
}

void set_hash(vector<int> &a)
{
    Hash.clear();
    srand(time(NULL));
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        auto it = Hash.find(a[i]);
        if (it == Hash.end())
        {
            Hash[a[i]] = rand46();
        }
    }
}

vector<int> solve(vector<int> &a, vector<vector<int>> &lr)
{
    int n = a.size();
    set_hash(a);
    vector<long long int> psum(n, 0LL);
    psum[0] = Hash[a[0]];
    for (int i = 1; i < n; i++)
    {
        psum[i] = psum[i-1] + Hash[a[i]];
    }
    int q = lr.size();
    vector<int> ans(q, 0);
    for (int i = 0; i < q; i++)
    {
        long long int lhs = psum[lr[i][1]] - (lr[i][0] > 0 ? psum[lr[i][0] - 1] : 0LL);
        long long int rhs = psum[lr[i][3]] - (lr[i][2] > 0 ? psum[lr[i][2] - 1] : 0LL);
        ans[i] = (lhs == rhs);
    }
    return ans;
}

int main()
{
    // vector<int> A = {1, 7, 11, 8, 11, 7, 1};
    vector<int> A = {1, 3, 2};
    // vector<vector<int>> B = {{0, 2, 4, 6}};
    vector<vector<int>> B = {{0, 1, 1, 2}};
    vector<int> result = solve(A, B);
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}