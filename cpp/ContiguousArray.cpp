#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int solve(vector<int> &A)
{
    int n = A.size();
    if (n == 0)
    {
        return 0;
    }
    unordered_map<int, int> map;
    int prefix_sum = 0, result = 0;
    map[0] = -1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
            prefix_sum--;
        else
            prefix_sum++;
        if (map.find(prefix_sum) == map.end())
            map[prefix_sum] = i;
        else
            result = max(result, i - map[prefix_sum]);
    }
    return result;
}

int main()
{
    vector<int> A1{0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0};
    vector<int> A2{1, 0, 1, 0, 1};
    vector<int> A3{1, 1, 1, 0};
    vector<int> A4{0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1};
    vector<int> A5{1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0};
    int result = solve(A5);
    cout << result << endl;
    return 0;
}