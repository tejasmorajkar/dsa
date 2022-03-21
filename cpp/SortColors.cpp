#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> sortColors(vector<int> &A) {
    vector<int> result;
    unordered_map<int, int> map;
    for (int i = 0; i < A.size(); i++)
    {
        if (map.find(A[i]) == map.end())
        {
            map[A[i]] = 1;
        } else {
            map[A[i]]++;
        }
    }
    int zero_count = map[0];
    int one_count = map[1];
    int two_count = map[2];

    for (int i = 0; i < zero_count; i++)
    {
        result.push_back(0);
    }
    for (int i = 0; i < one_count; i++)
    {
        result.push_back(1);
    }
    for (int i = 0; i < two_count; i++)
    {
        result.push_back(2);
    }
    return result;
}

int main()
{
    vector<int> A {0, 1, 2, 0, 1, 2};
    vector<int> result = sortColors(A);
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}