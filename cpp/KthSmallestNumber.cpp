#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kthsmallest(const vector<int> &A, int B) {
    vector<int> sorted_array_index;
    int min_index;
    vector<int> copy_vector (A.begin(), A.end());
    for (int i = 0; i < copy_vector.size() - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < copy_vector.size(); j++) {
            if (copy_vector[min_index] > copy_vector[j]) {
                min_index = j;
            }
        }
        // swap A[min_index] and A[i]
        if (copy_vector[i] != copy_vector[min_index]) {
            int temp = copy_vector[i];
            copy_vector[i] = copy_vector[min_index];
            copy_vector[min_index] = temp;
        }
        if (i == B - 1) {
            break;
        }
    }
    return copy_vector[B - 1];
}

int main()
{
    vector<int> A{2, 1, 4, 3, 2};
    int B = 2;
    int result = kthsmallest(A, B);
    printf("%d\n", result);
    return 0;
}