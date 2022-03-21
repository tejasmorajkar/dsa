#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Using sorting
// TC: O(nlogn)
// SC: O(1)
int solve(vector<int>& A) {
    int input_size = A.size();
    if (input_size < 2)
        return 0;
    sort(A.begin(), A.end());

    int steps = 0;

    for (int current_index = 1; current_index < input_size; current_index++) {
        int current_element = A[current_index];
        int prev_element = A[current_index - 1];
        if (current_element <= prev_element) {
            steps += (prev_element - current_element + 1);
            A[current_index] = A[current_index - 1] + 1;
        }
    }
    return steps;
}

int main()
{
    vector<int> A {2,4,3,4,5,3};
    int result = solve(A);
    printf("%d\n", result);
	return 0;
}
