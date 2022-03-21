#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool matches(int s1map[], int s2map[])
{
    for (int i = 0; i < 26; i++)
    {
        if (s1map[i] != s2map[i])
            return false;
    }
    return true;
}

int solve(string A, string B)
{
    if (A.length() > B.length())
    {
        return 0;
    }
    int a_map[26] = {0};
    int b_map[26] = {0};
    char a = 'a';
    int a_ascii = (int)a;
    for (int i = 0; i < A.length(); i++)
    {
        a_map[(int)A.at(i) - a_ascii]++;
        b_map[(int)B.at(i) - a_ascii]++;
    }
    int count = 0;
    for (int i = 0; i < B.length() - A.length(); i++)
    {
        if (matches(a_map, b_map))
        {
            count++;
        }
        b_map[(int)B.at(i + A.length()) - a_ascii]++;
        b_map[(int)B.at(i) - a_ascii]--;
    }
    if (matches(a_map, b_map))
    {
        count++;
    }
    return count;
}

int main()
{
    string A = "aca";
    string B = "acaa";
    int count = solve(A, B);
    printf("%d\n", count);
    return 0;
}