#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define MAX_CHAR 256

int findRank(string A)
{
    bool is_char_present[MAX_CHAR] = {false};
    long int i, j, str_length = A.size();
    for (i = 0; i < str_length; i++)
    {
        is_char_present[A[i]] = true;
    }
    long int factorial[MAX_CHAR];
    factorial[0] = 1;
    for (i = 1; i <= str_length + 1; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % 1000003;
    }
    long int rank = 0;
    for (i = 0; i < str_length; i++)
    {
        long int count = 0;
        for (j = 1; j <= (A[i]); j++)
        {
            if (is_char_present[j] == true)
                count++;
        }
        is_char_present[A[i]] = false;
        rank = (rank + (count - 1) * factorial[str_length - 1 - i]) % 1000003;
    }
    return (int)((rank + 1) % 1000003);
}

// Driver program to test above function
int main()
{
    string str = "DTNGJPURFHYEW";
    cout << findRank(str) << endl;
    return 0;
}