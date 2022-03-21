#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solve(vector<int> &A)
{
    vector<int> result;
    vector<vector<int> > possible_results;

    int n = A.size();

    if (n < 4)
    {
        return result;
    }

    unordered_map<int, vector<int> > map;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = A[i] + A[j];
            if (map.find(sum) == map.end())
            {
                map.insert({sum, {i, j}});
            }
            else
            {
                int a1 = map[sum][0];
                int b1 = map[sum][1];
                int c1 = i;
                int d1 = j;
                if (a1 < b1 && c1 < d1 && a1 < c1 && b1 != d1 && b1 != c1)
                {
                    possible_results.push_back({a1, b1, c1, d1});
                    map.erase(sum);
                }
            }
        }
    }

    if (possible_results.size() == 1)
    {
        return {possible_results[0][0], possible_results[0][1], possible_results[0][2], possible_results[0][3]};
    }
    int a = INT_MAX, b = INT_MAX, c = INT_MAX, d = INT_MAX;
    for (int i = 0; i < possible_results.size(); i++)
    {
        if (a > possible_results[i][0] ||
            (a == possible_results[i][0] && b > possible_results[i][1]) ||
            (a == possible_results[i][0] && b == possible_results[i][1] && c > possible_results[i][2]) ||
            (a == possible_results[i][0] && b == possible_results[i][1] && c == possible_results[i][2] && d > possible_results[i][3]))
        {
            result = possible_results[i];
            a = possible_results[i][0];
            b = possible_results[i][1];
            c = possible_results[i][2];
            d = possible_results[i][3];
        }
    }

    return result;
}

int main()
{
    vector<int> A{3, 4, 7, 1, 2, 9, 8};
    vector<int> result = solve(A);
    printf("Final result: ");
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}