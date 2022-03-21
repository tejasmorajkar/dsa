#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int solve(vector<int>& A, int B) {
    int min_num = 1e6;
    int max_num = 1;
    int input_size = A.size();
    unordered_map<int, int> frequency;

    for (int i = 0; i < input_size; i++) {
        min_num = min(A[i], min_num);
        max_num = max(A[i], max_num);
        frequency[A[i]]++;
    }

    while(min_num < max_num && B != 0) {
        if (frequency[min_num] < frequency[max_num]) {
            // Increment min_num
            if (frequency[min_num] > B) {
                break;
            } 
            frequency[min_num + 1] = frequency[min_num + 1] + frequency[min_num];
            B = B - frequency[min_num];
            min_num++;
        } else {
            // Decrement max_num
            if (frequency[max_num] > B) {
                break;
            }
            frequency[max_num - 1] = frequency[max_num - 1] + frequency[max_num];
            B = B - frequency[max_num];
            max_num--;
        }
    }

    return abs(max_num - min_num);
}

int main()
{
    vector<int> A{4, 6, 3, 1, 4};
    int B = 5;
    int cost = solve(A, B);
    printf("%d\n", cost);
	return 0;
}
