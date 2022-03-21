#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> wave(vector<int> &A) {
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size() - 1; i += 2) {
        swap(A[i], A[i + 1]);
    }
    return A;
}

int main()
{
    vector<int> A {1, 2, 3, 4};
    vector<int> result = wave(A);
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}