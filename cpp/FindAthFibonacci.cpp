#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int, int> dp;

int findAthFibonacci(int A) {
    if (A == 0)
    {
        return 0;
    }
    if (A == 1)
    {
        return 1;
    }
    if (dp.find(A) != dp.end())
    {
        return dp[A];
    }
    dp[A - 1] = findAthFibonacci(A - 1);
    dp[A - 2] = findAthFibonacci(A - 2);
    return dp[A - 1] + dp[A - 2];
}

int main()
{
    int result = findAthFibonacci(1);
    cout << result << endl;
	return 0;
}
