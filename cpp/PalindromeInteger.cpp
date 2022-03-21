#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int isPalindrome(int A) {
    if (A < 0 || (A != 0 && A % 10 == 0))
    {
        return 0;
    }
    int num = 0;
    while (A > num)
    {
        num = (num * 10) + (A % 10);
        A = A / 10;
    }
    if (num == A || A == (num / 10))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int A = 123;
    int result = isPalindrome(A);
    cout << result << endl;
	return 0;
}