#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void arrange(vector<int> &A)
{
    // First step: Increase all values by (arr[arr[i]]%n)*n
    for (int i = 0; i < A.size(); i++)
    {
        A[i] = A[i] + (A[A[i]] % A.size()) * A.size();
    }
        
    // Second Step: Divide all values by n
    for (int i = 0; i < A.size(); i++)
    {
        A[i] = A[i]/A.size();
    }
}

int main()
{
    vector<int> A{3,2,1,0};
    arrange(A);
    for (auto &i : A)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
