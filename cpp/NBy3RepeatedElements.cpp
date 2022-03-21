#include <iostream>
#include <vector>

using namespace std;

int repeatedNumber(const vector<int> &A) {
    int N = A.size();
    if (N == 0) return -1;
    if (N == 1) return A[0];

    int first = INT32_MAX, second = INT32_MAX, count1 = 0, count2 = 0;

    for (int i = 0; i < N; i++)
    {
        if (A[i] == first)
        {
            count1++;
        }
        else if (A[i] == second)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            first = A[i];
            count1++;
        }
        else if (count2 == 0)
        {
            second = A[i];
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] == first)  
        {
            count1++;
        }
        else if (A[i] == second)
        {
            count2++;
        }
    }

    if (count1 > N/3)
        return first;
    else if (count2 > N/3)
        return second;

    return -1;
}

int main()
{
    vector<int> A {1, 2, 3, 1, 1};
    int result = repeatedNumber(A);
    cout << result << endl;
    return 0;
}