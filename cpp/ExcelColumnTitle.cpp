#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <math.h>

using namespace std;

string convertToTitle(int A) {
    return A == 0 ? "" : convertToTitle((A - 1) / 26) + (char) ((A - 1) % 26 + 'A');
}

int main()
{
    int A = 27;
    string result = convertToTitle(A);
    cout << result << endl;
	return 0;
}
