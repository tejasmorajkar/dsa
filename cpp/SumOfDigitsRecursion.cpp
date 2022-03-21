#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solve(int A) {
    if (A == 0)
    {
        return 0;
    }
    return A%10 + solve(A/10);
}

// Non recursive
int solve2(int A) {
    int sum = 0;
    string str = to_string(A);
    for (int i = 0; i < str.length(); i++)
    {
        sum += str[i] - '0';
    }    
    return sum;
}

int main()
{
    clock_t start = clock();
    int result = solve(46);
    clock_t end = clock();
    cout << (double)(end - start)/CLOCKS_PER_SEC << endl;
    cout << result << endl;
	return 0;
}
