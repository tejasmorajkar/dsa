#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <math.h>

using namespace std;

int titleToNumber(string A) {
    int result = 0;
    for (auto& c: A)
    {
        result = (26 * result) + c - 'A' + 1;
    }
    return result;
}


int main()
{
    string A = "ABCD";
    int result = titleToNumber(A);
    cout << result << endl;
	return 0;
}
