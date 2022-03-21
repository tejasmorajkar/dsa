#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int uniquePaths(int A, int B)
{
    if (A == 1 || B == 1)
        return 1;
    A--;
    B--;
    if (A < B)
    { // Swap, so that m is the bigger number
        A = A + B;
        B = A - B;
        A = A - B;
    }
    long res = 1;
    int j = 1;
    for (int i = A + 1; i <= A + B; i++, j++)
    { // Instead of taking factorial, keep on multiply & divide
        res *= i;
        res /= j;
    }

    return (int)res;
}

int main()
{
    int A = 2, B = 2;
    int result = uniquePaths(A, B);
    cout << result << endl;
    return 0;
}
