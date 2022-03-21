#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int gcd(int A, int B);

int main()
{
    int A = 12;
    int B = 16;
    int result = gcd(A,B);
    cout << result << endl;
	return 0;
}

int gcd(int A, int B)
{
    int result;
    if (B == 0)
    {
        result = A;
    }
    else
    {
        result = gcd(B, A % B);
    }
    return result;
}