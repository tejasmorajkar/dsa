#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(vector<int> &A)
{
    vector<int> sorted_array_index;
    int min_index;
    for (int i = 0; i < A.size() - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < A.size(); j++) {
            if (A[min_index] > A[j]) {
                min_index = j;
            }
        }
        // swap A[min_index] and A[i]
        if (A[i] != A[min_index]) {
            int temp = A[i];
            A[i] = A[min_index];
            A[min_index] = temp;
        }
        sorted_array_index.push_back(min_index);
    }
    return sorted_array_index;
}

int main()
{
    vector<int> A {6, 4, 3, 7, 2, 8};
    vector<int> result = solve(A);
    return 0;
}