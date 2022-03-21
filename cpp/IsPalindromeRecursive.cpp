#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int is_palindrome(string A, int start, int end)
{
    if (start >= end)
    {
        return 1;
    }    
    if (A[start] == A[end])
    {
        return is_palindrome(A, start + 1, end - 1);
    }
    return 0;
}

int solve(string A) {
    return is_palindrome(A, 0, A.size() - 1);
}

int solve2(string A) {
    int start = 0;
    int end = A.length() - 1;

    while (start < end)
    {
        if (A[start] == A[end])
        {
            start++;
            end--;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    string A = "MADAM";
    int result = solve(A);
    cout << result << endl;
	return 0;
}
