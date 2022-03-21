#include <iostream>
#include <string>

using namespace std;

int countSubsequence(string A)
{
    int g_count = 0;
    int sub_seq_count = 0;
    int mod = 1e9 + 7;
    for (int i = A.length(); i >= 0; i--)
    {
        if (A[i] == 'G') {
            g_count++;
        } else if (A[i] == 'A') {
            sub_seq_count += g_count;
        }
    }
    return sub_seq_count % mod;
}

int main()
{
    int result = countSubsequence("ABCGAG");
    printf("%d\n", result);
    return 0;
}