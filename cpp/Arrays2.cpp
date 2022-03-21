#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> plusOne(vector<int> &A) {
	// Remove trailing 0's if any
	int i = 0;
	while ( i < A.size()) {
		if (A[0] == 0) {
			A.erase(A.begin());
			i++;
		} else {
			break;
		}
	}

	int number_of_digits = A.size();

	for (int i = number_of_digits - 1; i >= 0; i--) {
		if (A[i] < 9) {
			A[i] = A[i] + 1;
			return A;
		}
		else {
			A[i] = 0;
		}
	}

	A.insert(A.begin(), 1);
	return A;
}

vector<int> multiplicationPrevNext(vector<int> &A) {
	vector<int> result;

	for (int i = 0; i < A.size(); i++) {
		if (i == 0) {
			if (i + 1 < A.size()) {
				result.push_back(A[i] * A[i + 1]);
			} else {
				result.push_back(A[i]);
			}
		} else if (i == A.size() - 1) {
			if (i - 1 > 0) {
				result.push_back(A[i] * A[i - 1]);
			} else {
				result.push_back(A[i]);
			}
		} else {
			if (i - 1 >= 0 && i + 1 < A.size()) {
				result.push_back(A[i - 1] * A[i + 1]);
			}
		}
	}
	return result;
}

int primal_power(vector<int> &A) {
	int count = 0;

	for (int i = 0; i < A.size(); i++) {
		if (A[i] > 1) {
			bool isPrime = false;

			if (A[i] == 2 || A[i] == 3) {
				isPrime = true;	
			} else {
				int square_root = (int)sqrt(A[i]);
				for (int j = 2; j <= square_root; j++) {
					if (A[i] % j == 0) {
						isPrime = false;
						break;
					} else {
						isPrime = true;
					}
				}
			}
			if (isPrime) {
				count++;
			}
		}
	}

	return count;
}

vector<int> reverseArray(vector<int> &v, int start, int end) {
	int temp;
	vector<int> result(v.begin(), v.end());
	while (start < end) {
		temp = result[start];
		result[start] = result[end];
		result[end] = temp;
		start++;
		end--;
	}
	return result;
}

vector<int> rotate(vector<int> &v, int size, int k) {
	k = k % size;
	vector<int> temp1 = reverseArray(v, 0, k - 1);
	vector<int> temp2 = reverseArray(temp1, k, size - 1);
	vector<int> result = reverseArray(temp2, 0, size - 1);
	return result;
}

vector<vector<int>> multiple_left_rotation(vector<int> &A, vector<int> &B) {
	vector<vector<int>> result;

	for (int i = 0; i < B.size(); i++) {
		result.push_back(rotate(A, A.size(), B[i]));
	}
	return result;
}

int main() {
	// vector<int> input = {0, 0, 4, 4, 6, 0, 9, 6, 5, 1};
	// vector<int> result = plusOne(input);
	// for (int i = 0; i < result.size(); i++) { 
	// 	printf("%d ", result[i]);
	// }
	// printf("\n");

	// vector<int> input = {5, 17, 100, 11};
	// vector<int> result = multiplicationPrevNext(input);
	// for (int i = 0; i < result.size(); i++) { 
	// 	printf("%d ", result[i]);
	// }
	// printf("\n");

	// vector<int> input = {97, 43, 29, 11, 100, 47, 76, 83, 37, 19, 17, 19, 71, 0, 1, -82, 2, -83, 37, 13, 5, 97, 17, 30, 31, 48, 2, 19, 31, 91, 19, 2, 5, 89, 2, 67, 31, 47, 43, 31, 5, 17, 83, 11, 47, 73, 19, 3, 3, 19, 59, 91, 67, 7, 43, 4, 3, 51, 52, 23, 3, 37, 53, 89, 9, 41, 19, 61, 7, 5, 53, 59, 19, 11, 79, 37, 31, 37, 73, 82, 41, 2, 13, 8, 2, 36, 19, 58, 17, 17, 59, 59, 37, 11, 13, 37, 47, 83, 31, 3};
	// int result = primal_power(input);
	// printf("%d\n", result);

	vector<int> A = {5, 17, 100, 11};
	vector<int> B = {1};

	vector<vector<int>> result = multiple_left_rotation(A, B);
	for (int i = 0; i < result.size(); i++) { 
		for (int j = 0; j < result[i].size(); j++) { 
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
			
	return 0;
}