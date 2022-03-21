#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string solve(string A) {
    int str_len = A.length() - 1;
    for (int i = 0; i <= str_len/2; i++) {
        int temp = A[i];
        A[i] = A[str_len - i];
        A[str_len - i] = temp;
    }
    return A;
}

int main()
{
    string A = "academy";
    string result = solve(A);
    cout << result << endl;
	return 0;
}
