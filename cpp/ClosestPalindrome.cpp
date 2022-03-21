#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string solve(string A)
{
    int start = 0;
    int end = A.length() - 1;
    int count = 0;

    while (start < end)
    {
        if (A[start] != A[end])
        {
            count++;
        }
        start++;
        end--;
        if (count > 1)
        {
            break;
        }
    }
    if (count == 1 || (count == 0 && A.length() % 2 == 1))
    {
        return "YES";
    }
    return "NO";
}

int main()
{
    string A = "adaddb";
    string result = solve(A);
    cout << result << endl;
	return 0;
}
