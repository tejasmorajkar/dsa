#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string solve(string A) {
    A = A + A;
    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] >= 'A' && A[i] <= 'Z')
        {
            A.erase(i, 1);
            i--;
        } else if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u')
        {
            A[i] = '#';
        }
    }
    return A;
}

int main()
{
    string A = "AbcaZeoB";
    string result = solve(A);
    cout << result << endl;
	return 0;
}
