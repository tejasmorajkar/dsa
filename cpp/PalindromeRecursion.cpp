#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool is_palindrome(string& A, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    if (A[start] == A[end] && is_palindrome(A, start++, end--))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string A = "MADAM";
    is_palindrome(A, 0, A.length() - 1);
	return 0;
}
