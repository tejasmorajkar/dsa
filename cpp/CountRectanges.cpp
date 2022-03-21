#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solve(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[make_pair(A[i], B[i])]++;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // A[i], B[i]
            // A[j], B[j]
            // Check if above pair is diagonal 
            if (A[i] != A[j] && B[i] != B[j])
            {
                // Check if co-ordinates other than diagonals exist in map
                if (mp.find(make_pair(A[i], B[j])) != mp.end() &&
                    mp.find(make_pair(A[j], B[i])) != mp.end())
                {
                    count++;
                }
            }
        }
    }
    return count/2;
}

int main()
{
    // vector<int> A = {1, 1, 2, 2};
    // vector<int> B = {1, 2, 1, 2};
    // 1

    vector<int> A = {1, 1, 2, 2, 3, 3};
    vector<int> B = {1, 2, 1, 2, 1, 2};
    // 3
    int ans = solve(A, B);
    printf("%d\n", ans);
    return 0;
}