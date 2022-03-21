#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void reverse(string &str, int start, int end)
{
    while(start < end)
    {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

string solve(string A, int B) {
    B = B % A.length();
    reverse(A, 0, A.length() - 1);
    reverse(A, 0, B - 1);
    reverse(A, B, A.length() - 1);
    return A;
}

int main()
{
    string result = solve("scaler", 2);
    cout << result << endl;
	return 0;
}
